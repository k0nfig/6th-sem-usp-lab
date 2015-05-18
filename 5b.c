#include<stdio.h>
#include<unistd.h>

void main(int argc,char **argv)
{
	if(argc!=3)
	{
		perror("Input error");
		return;
	}
	if(link(argv[1],argv[2])==-1)
	{
		perror("Link fail");
		return;
	}
	printf("Link successfull\n");
	system("ls -l");
}
// Create a file by using "vi 1.txt" and then link it with a new file
// Don't give two new file names. It'll give an error
// Let one file be created and other one not yet created 
// check for the second column of the output. Both inode numbers of the files should be the same
