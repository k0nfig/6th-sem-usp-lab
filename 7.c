#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
{
	pid_t pid;
	int stat;
	if((pid=fork())<0)
	{
		perror("fork fail\n");
		return;
	}
	else if(pid==0)
	{
		exit(0);
	}
	else
	{
		//wait(&stat);
		system("ps -o stat,comm,pid,ppid,tty");
		//If your teacher is asking you to print only the zombie's status uncomment the below line
		//system("ps -o stat,comm,pid,ppid,tty | grep 'Z'");
		exit(0);
	}
}
// check for Z+ in the output! That's a ZOMbie!
// just uncomment the wait statement to prevent the zombie! The 20th statement!
