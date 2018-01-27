#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
extern int errno;
int main(int argc,char **argv)
{
	char actual[100];
	char linkpath[100];
	char ch;
	printf("Enter actual path\n");
	scanf("%s",actual);
	printf("Enter link path\n");
	scanf("%s",linkpath);
	printf("%s",linkpath);
	printf("\n%s\n",actual);
	/*if(link(actual,linkpath)!=0)
	{
		printf("%d",errno);
		perror("");
	}*/
	if(symlink(actual,linkpath)!=0)
	{
		printf("%d",errno);
		perror("");
	}
	return 0;
}
