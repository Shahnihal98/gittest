#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <math.h>


#define SHSIZE 100

void swap(float *p,float *q);

int main(){
    
    int shmid;
    key_t key;
    float* shm;
    int* s;
    float mean;
    float sum=0.0;
    float std=0.0;
    float ans;
    int i,j;
    float arr[10];
    
    key = 9876;
    
    shmid = shmget(key, SHSIZE, 0666);

    if (shmid < 0){
        perror("shmget");
        exit(1);
    }
    
    shm = (float*) shmat(shmid, NULL, 0);
     
    for(i=0; i<10; ++i)
    {    
	arr[i]=*shm;	
	sum += *shm;
        shm += sizeof(float);
	//sum += arr[i];
    }

    
	printf("\nsum = %f", sum);

    mean = sum/10;
	printf("\nmean = %f", mean);

    for(i=0; i<10; ++i)
        std += pow(arr[i] - mean, 2);

	ans=sqrt(std/10);

	printf("\nstd = %.6f", ans);
    
int n=10;
      
      for(i = 0; i<n-1; i++) {
      for(j = 0; j<n-i-1; j++) {
         if(arr[j] > arr[j+1])
            swap(&arr[j],&arr[j+1]);
      }
   }

 n = (n+1) / 2 - 1; 

   printf("\nMedian = %f", arr[n]);
    shmdt(shm);
    
    return 0;
}

void swap(float *p,float *q) {
   float t;
   
   t=*p; 
   *p=*q; 
   *q=t;
}

