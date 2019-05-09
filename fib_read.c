#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>


int main(void) {
	int fd, retval, val;
	int i,t1=0,t2=1,nextTerm;
	int arr[2];	

	fd = open("/tmp/myfifo",O_RDONLY);
	retval = read(fd, arr, sizeof(arr));

	val=arr[0];
	
	fflush(stdin);

	printf("Fibonacci Series: \n");

    for (i=1; i<=val; ++i)
    {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
	
	close(fd);
	return 0;
}
