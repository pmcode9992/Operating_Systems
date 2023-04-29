#include<stdio.h>
#include<unistd.h>
int main(){
        int pid=fork();
        if(pid==0){
                sleep(20);
                printf("Child Proces ID:  %d\n ",getppid());
                printf("If I get 1 as my parent ID then I am Orphan\n");
        }
        else{
                printf("   %d   ",getpid());
                printf("I am a parent\n");
        }
        return 0;
}