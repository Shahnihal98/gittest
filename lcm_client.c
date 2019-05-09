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
    int n1, n2, i, gcd;
    int arr[2];
    int lcm;
    
    key = 9876;
    
    shmid = shmget(key, SHSIZE, 0666);

    if (shmid < 0){
        perror("shmget");
        exit(1);
    }
    
    shm = (int*) shmat(shmid, NULL, 0);
    
    for (i=0; i<2; i++)
    {
    	arr[i]=*shm;	
        shm += sizeof(float);
	}
	
	n1=arr[0];
	n2=arr[1];
    
    for(i=1; i <= n1 && i <= n2; ++i)
    {
        // Checks if i is factor of both integers
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }
	
	printf("\nGCD: %d\n", gcd);
    lcm = (n1*n2)/gcd;
    printf("LCM: %d.", lcm);
    
    shmdt(shm);
    
    return 0;
}
