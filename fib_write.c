#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	
	int arr[2],i,n;
	int retval, fd;

    printf("Enter the number of terms: ");
    scanf("%d", &n);
	
	arr[0]=n;	

    
	fflush(stdin);
	
	retval = mkfifo("/tmp/myfifo",0666);
	fd = open("/tmp/myfifo",O_WRONLY);
	write(fd,arr,sizeof(arr));
	close(fd);
	return 0;
}
