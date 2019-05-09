#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#define SHSIZE 100

int main(){
    
    int shmid;
    key_t key;
    int* shm;
    int* s;
    int n1, n2, i, gcd, lcm;
    
    int arr[2];
    
    key = 9876;
    
    shmid = shmget(key, SHSIZE, IPC_CREAT | 0666);

    if (shmid < 0){
        perror("shmget");
        exit(1);
    }
    
    shm = (int*) shmat(shmid, NULL, 0);
    
    if (shm == (int *) -1 ){
        perror("shmat");
        exit(1);
    }
    
    printf("Enter two numbers: ");
    for (i=0; i<2; i++)
    {
    	scanf("%d", &arr[i]);
	}
	
	for (i=0; i<2; i++)
	{
		*shm=0;    	
		*shm=arr[i];
    	shm += sizeof(int);
	 } 
    
    //sleep(2);
    
    shmdt(shm);
 
    return 0;
}
