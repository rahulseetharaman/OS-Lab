#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
int main()
{
	DIR *dir;
	char dirname[100];
	int i;
	for(i=0;i<100;i++)
	{
		char ch;
		scanf("%c",&ch);
		if(ch=='\n')
		break;
		dirname[i]=ch;
	}
	dirname[i]='\0';
	//printf("dirname %s",dirname);	
	char name[100];
	char ch;
	printf("Enter string to search");
	for(i=0;i<100;i++)
	{
		scanf("%c",&ch);
		if(ch=='\n')
		break;
		name[i]=ch;
	}
	name[i]='\0';
	//printf("name %s",name);
	struct dirent *direntry;
	if((dir=opendir(dirname))==1)
	perror("");
	
	while((direntry=readdir(dir))!=NULL)
	{
		//printf("%s\n",direntry->d_name);
		if(strstr(direntry->d_name,name))
		printf("%s\n",direntry->d_name);
	}
	return 0;
}
