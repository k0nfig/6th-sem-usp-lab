#include<stdio.h>
#include<unistd.h>

void chardisp(char *ptr)
{
	char *str=ptr;
	int w;
	for(;w=*str;str++)
	{
		putc(w,stderr);
	}
}

void main()
{
	pid_t pid;
	if((pid=fork())<0)
	{
		perror("Fork fail\n");
		return;
	}
	else if(pid==0)
	{
		chardisp("I am child\n");
	}
	else
	{
		chardisp("Parent here\n");
	}
}
// For best results : Always compile before pressing ./a.out everytime
