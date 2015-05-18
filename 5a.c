#include<stdio.h>
#include<unistd.h>

void main()
{
	extern char **environ;
	char **p;
	printf("ENVIRONMENT VARIABLES\n");
	for(p=environ;*p!='\0';p++)
	{
		printf("%s\n",*p);
	}
}
