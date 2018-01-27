#include<fcntl.h>
#include<stdio.h>
int main()
{
	int status,options;
	int fd1;
	fd1=open("pmsample.txt",O_RDONLY);
	char ch[100];
	printf("Child process");
	read(fd1,ch,12);
	printf("\nString is %s",ch);
	return 0;
}