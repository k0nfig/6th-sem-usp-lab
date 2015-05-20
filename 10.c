#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#define INTERVAL 5

//callme is a function pointer. It is called when SIGALRM is encountered by the process
void callme(int signum)
{
	printf("Time up!\n");
}

void main()
{
	signal(SIGALRM,callme);//Setting up the signal handler for SIGALRM signal
	alarm(INTERVAL);//calling the alarm function to raise a SIGALRM signal
	pause();//Indefinite wait until a signal is caught
}
