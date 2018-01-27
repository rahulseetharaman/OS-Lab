#include<stdio.h>
#include<fcntl.h>
int main()
{
	int fd2;
	printf("Parent process\n");
	fd2=open("pmsample.txt",O_RDWR|O_CREAT);
	write(fd2,"Hello World",strlen("Hello World"));
	close(fd2);
	char * clargs[]={"./readfromfile.out",NULL};	
	execvp(clargs[0],clargs);
	return 0;
}
