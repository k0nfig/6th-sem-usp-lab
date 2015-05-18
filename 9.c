#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


void func(char *cmd)
{
	pid_t pid;
	if((pid=fork())<0)
	{
		wait(pid,NULL,0);
	}
	else if(pid==0)
	{
		execl("/bin/sh","sh","-c",cmd,NULL);
	}
}

void main(int argc,char **argv)
{
	int i;
	for(i=1;i<argc;i++)
	{
		func(argv[i]);
		printf("\n");
	}
}
