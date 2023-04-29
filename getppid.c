#include<stdio.h>
#include<unistd.h>
int main(){
        int a=fork();
        if(a==0){
                printf("I am a Child and my OS process ID is: %d\n",getpid());
                printf("My parent process ID is: %d\n",getppid());
        }
        else{
                printf("I am a Parent and my OS process ID is: %d\n",getpid());
                printf("My parent process ID is: %d\n",getppid());
        }
        return 0;
}