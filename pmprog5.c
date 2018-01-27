#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
int fd[2];
void * reader()
{
	int i=0;
	while(i<10)
	{
		char ch;
		int result;
		result=read(fd[0],&ch,1);
		printf("Reader %c\n",ch);
		i++;
	}
}
void *writer()
{
	int result,i=0;
	char ch='A';
	while(i<10)
	{
		result=write(fd[1],&ch,1);
		printf("Writer %c\n",ch);
		if(ch=='Z')
			ch='A'-1;
		ch++;
		i++;
	}
}
int main()
{
	pthread_t t1,t2;
	int r;
	r=pipe(fd);
	pthread_create(&t1,NULL,reader,NULL);
	pthread_create(&t2,NULL,writer,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;
}