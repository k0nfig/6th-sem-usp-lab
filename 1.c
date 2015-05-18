#include<stdio.h>
#include<unistd.h>
#include<limits.h>

void main()
{
	printf("No. of clock ticks %li\n",sysconf(_SC_CLK_TCK));
	printf("Max no. of child processes %li\n",sysconf(_SC_CHILD_MAX));
	printf("Max path length %li\n",pathconf("/",_PC_PATH_MAX));
	printf("Max number of characters in filename %li\n",pathconf("/",_PC_NAME_MAX));
	printf("Max no. of open files %li\n",sysconf(_SC_OPEN_MAX));
	return;
}
// The above program perfectly works even if %d is given. P.S : Neglect warnings! 
