#include<stdio.h>
#include<unistd.h>
#include<errno.h>
int main()
{
	char a[100];
	scanf("%s",a);
	unlink(a);
	return 0;
}
