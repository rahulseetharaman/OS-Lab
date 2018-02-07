#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
int main(int argc,char ** argv)
{
	DIR *dir;
	if((dir=opendir(argv[1]))==1)
	perror("");
	if(chdir(argv[1])==1)
	perror("");
	struct dirent *direntry;
	while((direntry=readdir(dir))!=NULL)
	{
		char *name;
		name=direntry->d_name;
		char ext[10];
		int count=0;
		int flag=0;
		int i;
		printf("%s\n",direntry->d_name);
		if(strcmp(name,"..")==0 || strcmp(name,".")==0)
                        continue;

		for(i=0;i<strlen(name);i++)
		{
			if(name[i]=='.')
			flag=1;
			else if(flag==1)
			ext[count++]=name[i];
		}
		if(flag==1)
		{
			DIR *dir2;
			ext[count]='\0';
			dir2=opendir(ext);
			if(dir2==NULL)
			mkdir(ext,0777);
			char a[100];
			strcpy(a,ext);
			strcat(a,"/");
			strcat(a,name);
			//printf("%s\n",a);
			int fd1=open(name,O_RDONLY,S_IRUSR);
			int n;
			char buf[1000];
			int count=0;
			while((n=read(fd1,buf,1))>0)
			{
				count++;
			}
			int fd2=open(a,O_RDWR|O_CREAT,S_IWUSR);
			write(fd2,buf,count);
			close(fd2);
		}
				
	}
	return 0;
}
	
			
			
