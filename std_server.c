#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <math.h>


#define SHSIZE 100

int main(){
    
    int shmid;
    key_t key;
    float* shm;
    int* s;
    int i;
    float sum=0.0, mean, std=0.0;
    float ans;
    
    float arr[10];
    
    key = 9876;
    
    shmid = shmget(key, SHSIZE, IPC_CREAT | 0666);

    if (shmid < 0){
        perror("shmget");
        exit(1);
    }
    
    shm = (float*) shmat(shmid, NULL, 0);
    
    if (shm == (float *) -1 ){
        perror("shmat");
        exit(1);
    }
    
    printf("Enter 10 elements: ");
    for(i=0; i<10; ++i)
        scanf("%f", &arr[i]);
        
    for(i=0; i<10; i++)
    {
	*shm=0;    	
	*shm=arr[i];
    	shm += sizeof(int);
	}
    
    //sleep(2);
    
    shmdt(shm);
 
    return 0;
}
