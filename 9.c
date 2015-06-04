#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


void func(char *cmd)//Recieves the command
{
	pid_t pid;
	if((pid=fork())<0)
	{
		perror("fork fail");
		exit(0);
	}
	else if(pid==0)
	{
		execl("/bin/sh","sh","-c",cmd,NULL);//exec is called to give the child a new job, here to execute the shell
                //-c is given to instruct exec function that the command is given through a pointer cmd
	}
	wait();//To make the command prompt get back after the execution of the command
}

void main(int argc,char **argv)
{
	int i;
	for(i=1;i<argc;i++)
	{
		func(argv[i]);//Since all the commands are passed as command line arguments we give it to exec
		printf("\n");
	}
}
