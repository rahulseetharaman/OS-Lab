#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
int main()
{
	int fd=open("f1.txt",O_RDWR,S_IRUSR|S_IWUSR|S_IXUSR);
	int n;
	char *buf=(char*)malloc(sizeof(char)*100);
	char *temp=(char*)malloc(sizeof(char)*100);
	int i=0;
	int tot=1;
	int ll;
	while((n=read(fd,buf,1)>0))
	{
           printf("%c",*buf);
           if(*buf=='\n')
	   {
		temp[i]='\0';
		//printf("Hi");	
		if(strcmp(temp,"Rahul studies in CEG")==0)
		{
			if(ftruncate(fd,tot)==0)
			printf("Truncation successful");
			else
			printf("Truncation Unsuccessful");
	        	break;
		}
		free(temp);
		tot+=i;
		i=0;
		temp=(char*)malloc(sizeof(char)*100);
           }
	   else
	   temp[i++]=*buf;
	   	
	}
	return 0;
}	   	
	   			   	
