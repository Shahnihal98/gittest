#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

void Swap(int *a,int *b);

int main(void) {
	int fd, retval;
	int fd2, retval2;
	int array[100];
	int array2[2];	
	int i,j,val;


	fd = open("/tmp/myfifo",O_RDONLY);
	fd2 = open("/tmp/myfifo",O_RDONLY);	
	retval = read(fd, array, sizeof(array));
	retval2 = read(fd2, array2, sizeof(array2));

	fflush(stdin);

	printf("Array received\n");
	
	val=array2[0];

	for(i=0;i<val-1;i++)
	{
		for(j=0;j<val-i-1;j++)
		{
			if(array[j]>array[j+1])
			Swap(&array[j],&array[j+1]);
		}
	}
	
	printf("Sorted Array: \n");
	for(int i=0;i<val;i++)
	{
		printf("%d\n", array[i]);
	}
}

void Swap(int *a,int *b)

{

	int temp;

	temp=*a;

	*a=*b;

	*b=temp;

}	
