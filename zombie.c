#include<stdio.h>
#include<unistd.h>
int main(){
        int pid=fork();
        if(pid==0){
                printf("I am a Child\n");
        }
        else{
                sleep(10);
                printf("I am a Parent\n");
        }
        return 0;
}