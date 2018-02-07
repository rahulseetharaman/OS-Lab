#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int foo(int fd,char *buf,int b_size,int n,int skip)
{
	int nb;
	int tot=0;
	while(1)
	{
		nb=read(fd,buf,n);
		if(nb<=0)
		break;
		tot+=n;
		lseek(fd,skip,SEEK_CUR);
	}
	return tot;
}
int main()
{
	int fd=open("spotinput1.txt",O_RDONLY,S_IRUSR);
	char buf[1000];
	int ans=foo(fd,buf,sizeof(buf),10,2);
	printf("%d bytes read",ans);
	return 0;
}	
