#include<stdio.h>
#include<unistd.h>
#include<errno.h>
extern int errno;
int main()
{
	char old[100];
	char new[100];
	char nc;
	scanf("%s",old);
	scanf("%c",nc);
	scanf("%s",new);
	if(rename(old,new)!=0)
	{
		perror("");
	}
	return 0;
}
