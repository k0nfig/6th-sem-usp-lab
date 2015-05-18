#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#define INTERVAL 5

void callme(int signum)
{
	printf("Time up!\n");
}

void main()
{
	signal(SIGALRM,callme);
	alarm(INTERVAL);
	pause();
}
