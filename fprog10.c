#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<sys/stat.h>
extern int errno;
int main(int argc,char **argv)
{
	DIR *dir;
	struct dirent *direntry;
	struct stat statbuf;
	mode_t file_type,file_perm;
	if((dir=opendir(argv[1]))==1)
		perror("");
	if(chdir(argv[1])==-1)
		perror("");
	while((direntry=readdir(dir))!=NULL)
	{
		if(lstat(direntry->d_name,&statbuf)<0)
		{	
			perror("lstat");
			continue;
		}
		if(S_ISDIR(statbuf.st_mode))
		{
			file_type=statbuf.st_mode & S_IFMT;
			file_perm=statbuf.st_mode & ~S_IFMT;
			printf("%o %o %s\n",file_type,file_perm,direntry->d_name);
		}
	}
	return 0;
}	
			
