#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>


int main(void) {
	int fd, retval;
	int fd2, retval2;
	int fd3, retval3;
	int buffer[10][10];
	int buffer2[10][10];
	int multiply[10][10];
	int buffer3[4];	
	int i,j,k;
	int r1,r2,c1,c2;
	int sum=0;

	fd = open("/tmp/myfifo",O_RDONLY);
	fd2 = open("/tmp/myfifo",O_RDONLY);	
	fd3 = open("/tmp/myfifo",O_RDONLY);
	retval = read(fd, buffer, sizeof(buffer));
	retval2 = read(fd2, buffer2, sizeof(buffer2));
	retval3 = read(fd3, buffer3, sizeof(buffer3));

	fflush(stdin);

	printf("Matrix received\n");
	
	r1=buffer3[0];
	c1=buffer3[1];
	r2=buffer3[2];
	c2=buffer3[3];

	for (i=0; i<r1; i++) 
	{
      for (j=0; j<c2; j++) 
	  {
        for (k=0; k<r2; k++) {
          sum=sum + buffer[i][k]*buffer2[k][j];
        }
 
        multiply[i][j] = sum;
        sum = 0;
      }
    }
 
    printf("Product of the matrices:\n");
 
    for (i=0; i<r1; i++) 
	{
      for (j=0; j<c2; j++)
      {
        printf("%d\t", multiply[i][j]);
 		printf("\n");
      }
    }
	
	close(fd);
	close(fd2);
	close(fd3);
	return 0;
}
