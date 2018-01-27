#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
//the program reads a file in reverse
int main()
{
	char buf;
	int fd;
	fd=open("f1.txt",O_RDONLY,S_IRUSR);
	int n;
	int size=lseek(fd,-1,SEEK_END);
	while(size >=0)
	{
	   n=read(fd,&buf,1);
	   printf("%c",buf);
	   size=lseek(fd,-2,SEEK_CUR);
	}
	return 0;
}
