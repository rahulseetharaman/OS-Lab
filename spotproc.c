#include<stdio.h>
#include<fcntl.h>
int main(int argc,char **argv)
{
	char ch;
	pid_t pid=fork();
	if(pid!=0)
	{
		printf("Parent process\n");
		char *clargs[]={"./writetofile.out",NULL};
		execvp(clargs[0],clargs);
	}	
	else
	{	
		printf("child process");
                char *clargs[]={"./readfromfile.out",NULL};
		execvp(clargs[0],clargs);
	}	
	return 0;
}	
