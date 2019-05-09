#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	int fd, retval;
	int fd2, retval2;
	int fd3, retval3;
	int r1,c1,r2,c2;
	int i,j;
	
	int buffer[10][10];
	int buffer3[4];
	
	printf("Enter number of rows of 1st matrix: \n");
	scanf("%d", &r1);

	printf("Enter number of columns of 1st matrix: \n");
	scanf("%d", &c1);

	printf("Enter elements of first matrix: \n");
 
  	for (i=0; i<r1; i++)
  	{
  		  for (j=0; j<c1; j++)
  		  {
  		  	 scanf("%d", &buffer[i][j]);
		  }
	}
	
	
	int buffer2[10][10];

	printf("Enter number of rows of 2nd matrix: \n");
	scanf("%d", &r2);

	printf("Enter number of columns of 2nd matrix: \n");
	scanf("%d", &c2);
	
	printf("Enter elements of second matrix: \n");
	 
	 	for (i=0; i<r2; i++)
  	{
  		  for (j=0; j<c2; j++)
  		  {
  		  	 scanf("%d", &buffer2[i][j]);
		  }
	}

	buffer3[0]=r1;
	buffer3[1]=c1;
	buffer3[2]=r2;
	buffer3[3]=c2;
    
	fflush(stdin);
	
	retval = mkfifo("/tmp/myfifo",0666);
	retval2 = mkfifo("/tmp/myfifo",0666);
	retval3 = mkfifo("/tmp/myfifo",0666);
	fd = open("/tmp/myfifo",O_WRONLY);
	fd2 = open("/tmp/myfifo",O_WRONLY);
	fd3 = open("/tmp/myfifo",O_WRONLY);
	write(fd,buffer,sizeof(buffer));
	write(fd2,buffer2,sizeof(buffer2));	
	write(fd3,buffer3,sizeof(buffer3));
	close(fd);
	close(fd2);
	close(fd3);
	return 0;
}
