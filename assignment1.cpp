//assignment 1
// execution of parent and child process with fork()

#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 

void func() 
{ 
    if (fork() == 0) 
        printf("Hello from Aayu child!\n"); 
    else
        printf("Hello from Ayush!\n"); 
}

int main()
{
    func();
    return 0;
}
