#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
using namespace std;

int main(int argc,char **argv)
{
	int fd;
	char buf[50];
	if(argc!=2)
	{
		cout<<"Input error\n";
		return 0;
	}
	fd=open(argv[1],O_RDONLY); //Opening the same common file given as an argument in both terminals
	cout<<"Waiting for data to be entered in the write terminal\n";
	while(read(fd,buf,50)==-1)//read function returns -1 if the file is empty
	{
		;//making the terminal wait until data is entered
	}
	puts(buf);
	cout<<"Data read!\n";
	close(fd);
	return 0;
}
