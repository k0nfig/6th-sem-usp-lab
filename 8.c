#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	pid_t pid1,pid2;
	int stat1;
	if((pid1=fork())<0)//Creating the child1
	{
		perror("Fork fail\n");
		exit(0);
	}
	else if(pid1==0)//Inside the child1
	{
		if((pid2=fork())<0)//Creating the child2
		{
			perror("Fork fail\n");
			exit(0);
		}
		else if(pid2==0)//Inside the child2
		{
			sleep(2);//2 secs is a big time for cpu which works in microseconds
			//The cpu will execute the child1 in the meantime and comes back to child2
			
		}
		else
		{
			exit(0);//We are killing the child1 to ensure init adopts the child2 process
		}
	}
	else
	{
		sleep(2);//To make sure children execute first
		wait(&stat1);//Calling wait to ensure child1 is not a zombie
		system("ps -o stat,comm,pid,ppid,tty");//Printing status of each process
		exit(0);
	}
}
			
