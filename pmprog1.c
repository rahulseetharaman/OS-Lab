#include<stdio.h>
int main(int argc, char const *argv[])
{
	int pid=fork();
	if(pid==0)
	{
		printf("Child process\n");
	}
	else
	{
		printf("Parent process\n");
	}
	return 0;
}
