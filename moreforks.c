#include<stdio.h>
#include<unistd.h>
int main(){
        fork();
        fork();
        printf("  HEY\n");
        return 0;
}