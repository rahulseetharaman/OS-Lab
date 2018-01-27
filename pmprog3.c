#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char const *argv[])
{
	pid_t pid=fork();
	int var=1;
	if(pid<0)
	{
		perror("Fork Failed");
	}
	else if(pid==0)
	{
		char *args[]={"./cla.out","Rahul",NULL};
		execv(args[0],args);
		var=0;
		printf("Child process executing..\n");
	}
	printf("Var is %d\n",var);
	printf("Parent process executing..\n");
	wait(NULL);
	return 0;
}
