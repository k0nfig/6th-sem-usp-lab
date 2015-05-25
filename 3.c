#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

void main(int argc,char **argv)
{
	int fd;
	char buf[150];
	struct flock f;
        //Provide 2 arguments. ./a.out and the filename!
	if(argc!=2)
	{
		perror("Input error");
		return;
	}
        //open the file for both read and write!
	fd=open(argv[1],O_RDWR);
	printf("Press enter to lock\n");
	getchar();
        //Defining all the locking conditions
	f.l_type=F_WRLCK; //Type of lock : Write lock
	f.l_whence=SEEK_END; //Cursor pointing : End of the file
	f.l_start=SEEK_END-100;//Start : last 100 characters from the end of the file(i.e 0)
	f.l_len=100;//Length of lock: Till 100 characters from the last 100th character
	if((fcntl(fd,F_SETLK,&f))==-1) // SETLOCK : If the lock is being set by other process then it returns -1
	{
		fcntl(fd,F_GETLK,&f); //F_GETLK=Get the details of the process which has locked the file and store it in f
		printf("Cannot lock Already locked file\n")
		printf("Pid is %d\n",f.l_pid);//Printing pid of the process which has locked it!
		return;
	}
	printf("Locked\n");
	getchar();//to check in the other terminal for locking condition. Press enter key again!
	//Press ctl+shift+t for new terminal
	if(lseek(fd,SEEK_END-50,SEEK_END)==-1)//Cursor should point in the last 50th position
	{
		perror("Lseek error");
		exit(0);
	}
	if(read(fd,buf,50)==-1)//Reading 50 characters from the file and storing it in buf
	{
		perror("read error");
		exit(0);
	}
	puts(buf);//Prints it onto the standard output
	f.l_type=F_UNLCK;//Type of lock : unlock
	f.l_whence=SEEK_SET;//Cursor position : from the beginning
	f.l_start=0;//Start:0th position(starting of the file)
	f.l_len=0;//Length : 0 from the starting position
        //Read the above statement like this: It allows 0 positions to set the lock. i.e unlock the whole file!
        //if start=0 and len=0 then the lock is applied on the whole file!
	if((fcntl(fd,F_UNLCK,&f))==-1)//Setting up the lock
	{
		perror("fcntl error");
		return;
	}
	printf("Unlocked\n");
	close(fd);//Closing the file!
	return;
}
