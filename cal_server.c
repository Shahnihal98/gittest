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
    float* shm;
    char* shm2;
    int* s;
    char op;
    float firstNumber,secondNumber;
    float arr[2];
    char arr2[2];
    int i;
    
    key = 9876;
    
    shmid = shmget(key, SHSIZE, IPC_CREAT | 0666);

    if (shmid < 0){
        perror("shmget");
        exit(1);
    }
    
    shm = (float*) shmat(shmid, NULL, 0);
    shm2 = (char*) shmat(shmid, NULL, 0);
    
    if (shm == (float *) -1 )
	{
        perror("shmat");
        exit(1);
    }
    
    if (shm2 == (char *) -1 )
	{
        perror("shmat");
        exit(1);
    }
    
    printf("Enter an operator (+, -, *,): ");
    scanf("%c", &op);
    
    printf("Enter two operands: ");
    scanf("%f %f",&firstNumber, &secondNumber);
    
    arr[0]=firstNumber;
    arr[1]=secondNumber;
    
    
    for(i=0; i<2; i++)
    {
		*shm=0;    	
		*shm=arr[i];
    	 shm += sizeof(int);
	}
	
	arr2[0]=op;
	
	 *shm2=0;
	 *shm2=arr2[0];
	
    //sleep(2);
    
    shmdt(shm);
    shmdt(shm2);
 
    return 0;
}
