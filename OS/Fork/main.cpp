#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int main()
{
    pid_t pid;
    pid=fork();
    if(pid<0)
    {
        fprintf(stderr,"Fork Failed ");
        return 0;

    }
    else if(pid==0)
    {
        execlp("bin/ls", "ls", NULL);
        printf(" \n\nCHild Executing ");
    }
    else
    {
        pid=wait(NULL);
        printf(" \n\nChild Completed \n\n");
    }
    return 0;
}
