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
	cout<<"Enter Data\n";
	gets(buf);
	if((access(argv[1],F_OK))==-1)
	{
		mkfifo(argv[1],0777);
		cout<<"File created!\n";
	}
	fd=open(argv[1],O_WRONLY);
	res=write(fd,buf,sizeof(buf));
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
// give a file 1.txt(say) as command line argument
// in the write terminal(write something and press enter!)
// see it in the read terminal
// Enjoy!
