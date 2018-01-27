#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
extern int errno;
int main()
{
	int fd=open("f1.txt",O_RDWR,S_IRUSR|S_IWUSR|S_IXUSR);
	printf("The file descriptor is %d\n",fd);
	if(fd==-1)
	{
		printf("Error number %d\n",errno);
 		perror("Program\n");
	}
        int n;
        char *buf;
	buf=(char*)malloc(sizeof(char)*100);
	while((n=read(fd,buf,1))>0)
	printf("%c",*buf);
	char buf2[]="Rahul studies in CEG";
        for(int i=0;i<strlen(buf2);i++)
	{
		write(fd,buf2+i,1);
	}	
	close(fd);
	return 0;
}
		
