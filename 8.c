#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	pid_t pid1,pid2;
	int stat1;
	if((pid1=fork())<0)
	{
		perror("Fork fail\n");
		exit(0);
	}
	else if(pid1==0)
	{
		if((pid2=fork())<0)
		{
			perror("Fork fail\n");
			exit(0);
		}
		else if(pid2==0)
		{
			sleep(2);
		}
		else
		{
			exit(0);
		}
	}
	else
	{
		sleep(2);
		wait(&stat1);
		system("ps -o stat,comm,pid,ppid,tty");
		exit(0);
	}
}
			
