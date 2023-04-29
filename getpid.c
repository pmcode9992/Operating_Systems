#include<stdio.h>
#include<unistd.h>
int main(){
        int a=fork();

        if(a==0){
                printf("I am a child and my OS process ID is: %d\n",getpid());
        }
        else{
                printf("I am a Parent and my OS process ID is: %d\n",getpid());
        }
        return 0;
}