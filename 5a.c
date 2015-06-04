#include<stdio.h>
#include<unistd.h>

void main()
{
	//Okay, if you have to print a specific environment variable then uncomment all the below line
	extern char **environ;
	char **p,*d,*cmd="SHELL";//Give the environment variable whichever you want to print for ex. SHELL 
	printf("ENVIRONMENT VARIABLES\n");
	for(p=environ;*p!='\0';p++)
	{
		//d=strstr(*p,cmd);
		//if(d)
		//{
			printf("%s\n",*p);
		//}
	}
}
