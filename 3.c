#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

void main(int argc,char **argv)
{
	int fd;
	char buf[150];
	struct flock f;
	if(argc!=2)
	{
		perror("Input error");
		return;
	}
	fd=open(argv[1],O_RDWR);
	printf("Press enter to lock\n");
	getchar();
	f.l_type=F_WRLCK;
	f.l_whence=SEEK_SET;
	f.l_start=0;
	f.l_len=100;
	if((fcntl(fd,F_SETLK,&f))==-1)
	{
		fcntl(fd,F_GETLK,&f);
		printf("Pid is %d\n",f.l_pid);
	}
	printf("Locked\n");
	if(lseek(fd,SEEK_END-50,SEEK_END)==-1)
	{
		perror("Lseek error");
		exit(0);
	}
	if(read(fd,buf,50)==-1)
	{
		perror("read error");
		exit(0);
	}
	puts(buf);
	f.l_type=F_UNLCK;
	f.l_whence=SEEK_SET;
	f.l_start=0;
	f.l_len=0;
	if((fcntl(fd,F_UNLCK,&f))==-1)
	{
		perror("fcntl error");
		return;
	}
	printf("Unlocked\n");
	close(fd);
	return;
}
