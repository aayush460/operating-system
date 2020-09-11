/*A C program to show multiple threads with local, global and static variables. 
Create three threads and print the value of the static, global and local variable. */

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
int g = 0; //global variable
void *Function(void *vargp) 
{ 
    int *myid = (int *)vargp; 
    static int s = 0; //static variable
    ++s; 
    ++g; 
    int l= 9;//local variable
    printf("Thread ID: %d, Static: %d, Global: %d, Local: %d\n", *myid,s,g,l); 
} 
int main() 
{ 
    int i; 
    pthread_t tid; 
    //Creation of three threads 
    for (i = 0; i < 3; i++) 
        pthread_create(&tid, NULL, Function, (void *)&tid); 
  
    pthread_exit(NULL); 
    return 0; 
}
