#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
int main()
{
	mode_t oldmode;
	oldmode=umask(0);
	printf("Previous umask:%o",oldmode);
	open("f1.txt",O_RDONLY|O_CREAT,0777);
	umask(oldmode);
	open("f1.txt",O_RDWR|O_CREAT,0764);
	printf("\n%o",0777-oldmode);
	exit(0);
	return 0;
}
