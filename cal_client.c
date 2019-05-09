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
    
    shmid = shmget(key, SHSIZE, 0666);

    if (shmid < 0){
        perror("shmget");
        exit(1);
    }
    
    shm = (float*) shmat(shmid, NULL, 0);
    shm2 = (char*) shmat(shmid, NULL, 0);
    
    
    for(i=0; i<2; ++i)
    {    
		arr[i]=*shm;	
    	shm += sizeof(float);
    }
    
    arr2[0]=*shm2;
    op=arr2[0];
    
	firstNumber=arr[0];
secondNumber=arr[1];
    switch(op)
    {
        case '+':
            printf("%.1f + %.1f = %.1f",firstNumber, secondNumber, firstNumber + secondNumber);
            break;

        case '-':
            printf("%.1f - %.1f = %.1f",firstNumber, secondNumber, firstNumber - secondNumber);
            break;

        case '*':
            printf("%.1f * %.1f = %.1f",firstNumber, secondNumber, firstNumber * secondNumber);
            break;

        case '/':
            printf("%.1f / %.1f = %.1f",firstNumber, secondNumber, firstNumber / secondNumber);
            break;

        // operator doesn't match any case constant (+, -, *, /)
        default:
            printf("Error! operator is not correct");
    }
    
    
    
    shmdt(shm);
    shmdt(shm2);
    
    return 0;
}
