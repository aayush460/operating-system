#include<unistd.h>
#include<stdlib.h>
int main()
{
    int pid,j;
    pid=fork();
    if(pid==0)
    {
        for(j=1;j<=10;j++)
         printf(1\nChild here\);
        exit(0);
    }
    else 
    {
        for(j=1;j<=10;j++)
         printf(1\nParent here\);

    }
   exit(0);
}
