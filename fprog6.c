#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
int main()
{
	char *path;	
	printf("Enter path");
	scanf("%s",path);
	if(mkdir(path,0777)==1)
	{
		printf("Not Successful");
		exit(1);
	}
	if(chdir(path)==-1)
	printf("Unable to change directory\n");
	char *newdir=(char*)malloc(sizeof(char) * 100);
	getcwd(newdir,100);
	printf("%s",newdir);
	return 0;
}
