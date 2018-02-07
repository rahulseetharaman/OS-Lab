#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
char *a[100];
int count=0;
void find(DIR *dir)
{
	struct dirent *direntry;
	while((direntry=readdir(dir))!=NULL)
	{
		if((lstat(direntry->d_name,&statbuf))<0)
		perror("stat");
		if(S_ISDIR(statbuf.st_mode))
		{
			a[count++]=direntry->d_name;
			find(opendir(direntry->d_name));
		}
	}
}	
	
int main(int argc,char **argv)
{
	DIR *dir;
	struct dirent *direntry;
	struct stat statbuf;
	mode_t file_type,file_perm;
	if((dir=opendir(argv[1]))=1)
	perror("");
	if(chdir(argv[1])==-1)
	perror("");
	while((direntry=readdir(dir))!=NULL)
	{
		/*if(lstat(direntry->d_name,&statbuf)<0)
		{
			perror("lstat");
			continue;
		}
		if(entries[direntry->d_name])
		{
			int yn;
			printf("Duplicate found %s",direntry->d_name);
			printf("\nWant to delete? press 1");
			if(yn==1)
			{
				//code for removing file
				
			}
		}
		else
		entries[direntry->d_name]=true;
		file_type=statbuf.st_mode & S_IFMT;
		file_perm=statbuf.st_mode & ~S_IFMT;
		printf("%o %o\n",file_type,file_perm);*/
		for(int i=0;i<count;i++)
		printf("%s\n",a[i]);
		
	}
	return 0;
}		
