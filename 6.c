#include<stdio.h>
#include<unistd.h>

//To display each character at a time! To show both parent and child have conflicting behaviours
void chardisp(char *ptr)
{
	char *str=ptr;
	int w;
	for(;w=*str;str++)
	{
		putc(w,stderr);// putc(int,FILE &);
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
		chardisp("I am child\n");//Fork does not guarntee who executes first. whether parent or child
	}
	else
	{
		chardisp("Parent here\n");
	}
}
// For best results : Always compile before pressing ./a.out everytime
//Compile each and everytime before executing to get different answers!!
