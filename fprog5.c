#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
int main(int argc,char **argv)
{
	DIR *dir;
	struct dirent *direntry;
	if((dir=opendir(argv[1]))==NULL)
	printf("Directory does not exist");
	while((direntry=readdir(dir))!=NULL)
	printf("%d %s\n",direntry->d_ino,direntry->d_name);
	closedir(dir);
	exit(0);
	return 0;
}
