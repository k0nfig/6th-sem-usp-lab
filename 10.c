#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#define INTERVAL 5

//callme is a function pointer. It is called when SIGALRM is encountered by the process
void callme(int signum)
{
	printf("Time up!\n");
}

//Heard that there are some issues with your teacher if you use the below signal() function!
void main()
{
	signal(SIGALRM,callme);//Setting up the signal handler for SIGALRM signal
	alarm(INTERVAL);//calling the alarm function to raise a SIGALRM signal
	pause();//Indefinite wait until a signal is caught
}
//Uncomment the below function for the sigaction method of invoking alarm
/*void main()
{
	struct sigaction action;//Creating a structure object called action
	//sigemptyset(&(action.sa_mask));//Clearing junk mask values inside the action object
	action.sa_handler=callme;//the handler should be call me
	if((sigaction(SIGALRM,&action,0))==-1)//Read the statement like this : If a signal called SIGALRM arrives handle it by the information given in action
	{
		perror("sigaction error");
	}
	alarm(INTERVAL);
	pause();//Indefinite wait for the signal to occur
}*/

