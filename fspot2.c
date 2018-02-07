#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
int main(int argc,char ** argv)
{
	int opfd=open("spout.txt",O_CREAT|O_RDWR,S_IRUSR|S_IWUSR|S_IXUSR);
	DIR *dir;
	struct dirent *direntry;
	if((dir=opendir(argv[1]))==1)
	perror("");
	if(chdir(argv[1])==1)
	perror("");
	while((direntry=readdir(dir))!=NULL)
	{
		char *name;
		name=direntry->d_name;
		char ext[10];
		int count=0;
		int flag=0;
		int i;
		//printf("%s\n",name);
		for(i=0;i<strlen(name);i++)
		{
			
			if(name[i]=='.')
			flag=1;
			else if(flag==1)
			ext[count++]=name[i];
		}
		ext[count]='\0';
		if(strcmp(ext,"text")==0)
		{
			printf("%s\n",name);
			int fd=open(name,O_RDONLY);
			int n;
			char buf[1000];
			while((n=read(fd,buf,1))>0)
			{
				char ch=*buf;
				write(opfd,&ch,1);
			}
			close(fd);
		}
	}
	close(opfd);
	return 0;
}
	
			
			
