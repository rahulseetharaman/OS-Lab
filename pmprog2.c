#include<stdio.h>
int main(int argc, char const *argv[])
{
	printf("Process id %d\n",(int)getpid());
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("Child Process %d\n",(int)getpid());
	}
	else
	{
		printf("Parent Process %d\n",(int)getpid());
	}
	return 0;
}
