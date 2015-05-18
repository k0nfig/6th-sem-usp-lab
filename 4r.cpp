#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
using namespace std;

int main(int argc,char **argv)
{
	int fd,res=0;
	char buf[50];
	if(argc!=2)
	{
		cout<<"Input error\n";
		return 0;
	}
	fd=open(argv[1],O_RDONLY);
	res=read(fd,buf,50);
	puts(buf);
	cout<<"Data read!\n";
	close(fd);
	return 0;
}
