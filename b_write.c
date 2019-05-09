#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	
	int array[100];
	int array2[2];
	int num;
	int i;
	int fd,fd2,retval,retval2;
	
	printf("Enter number of elements: ");
	scanf("%d", &num);
	
	printf("Enter elements: ");
	for (i=0; i<num; i++)
	{
		scanf("%d", &array[i]);
	}
	
	array2[0]=num;

	fflush(stdin);
	
	retval = mkfifo("/tmp/myfifo",0666);
	retval2 = mkfifo("/tmp/myfifo",0666);
	fd = open("/tmp/myfifo",O_WRONLY);
	fd2 = open("/tmp/myfifo",O_WRONLY);
	write(fd,array,sizeof(array));
	write(fd2,array2,sizeof(array2));	
	close(fd);
	close(fd2);
	return 0;
}
