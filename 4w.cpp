#include<iostream>
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

int main(int argc,char **argv)
{
	int fd,res;
	char buf[20];
	if(argc!=2)
	{
		perror("Input error");
		return 0;
	}
	if((access(argv[1],F_OK))==-1) //access function returns -1 if the file is not yet created
	{
		mkfifo(argv[1],0777); //creating a fifo file for communication
		cout<<"File created!\n";
	}
	cout<<"Enter Data\n";
	gets(buf);
	fd=open(argv[1],O_WRONLY);//opening the file for write purpose only
	res=write(fd,buf,sizeof(buf)); //writing data onto file (always give a new file in the argument)
	if(res==-1)
	{
		perror("Write error");
		exit(0);
	}
	close(fd);
}
// Open two different terminals
// ctrl+shift+t
// in one terminal type
// g++ 4w.cpp -o 4w.out
// ./4w.out 1.txt
// in another terminal type
// g++ 4r.cpp -o 4r.out
// ./4r.out 1.txt
// give a file 1.txt(say) as command line argument "GIVE A NEW FILE" P.s it's not necessary.
// in the write terminal(write something and press enter!)
// the read terminal waits until you give the input 
// see it in the read terminal
// Enjoy!
