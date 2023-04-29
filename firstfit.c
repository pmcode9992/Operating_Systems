#include<stdio.h>
void display(int mr[],int ho[],int ac[],int j, int h){
    printf("Requirements table\n_____________________\n");
    for(int i=0;i<j;i++){
        printf("J%d     %d\n",i,mr[i]);
    }
    printf("Holes table\n_________________________\n");
    for(int i=0;i<h;i++){
        printf("H%d     %d\n",i,ho[i]);
    }
    printf("Allocated blocks table\n_________________________\n");
    for(int i=0;i<j;i++){
        printf("A%d     %d\n",i,ac[i]);
    }
}
int allocator(int ho[],int h, int mem){
    int m=0,mini=-1;
    for(int i=0;i<h;i++){
        if(mem<ho[i]){
            if(m<ho[i]){
                m=ho[i];
                mini=i;
            }
        }
    }
    return mini;
}

int main()
{

    int j=4,h=5;
    int ac[4];
    //int mr[j],ac[j],ho[h];
    /*printf("Enter number of jobs");
    scanf("%d",&j);
    printf("Enter memory requirements\n");
    for(int i=0;i<j;i++){
        scanf("%d",&mr[i]);
    }
    printf("Enter number of holes");
    scanf("%d",&h);
    printf("Enter holes\n");
    int ho[j];
    for(int i=0;i<h;i++){
        scanf("%d",&ho[i]);
    }*/
    int mr[4]={90,50,30,40};
    int ho[5]={20,100,40,200,10};
    for(int i=0;i<j;i++){
        ac[i]=0;
    }
    
    display(mr,ho,ac,j,h);
    int done=0,i=0,k=0,g=0,accomodated=0,m=1000000,mini=-1;
    while(i<j)
    {
        ho[allocator(ho,h,mr[i])]-=mr[i];
        ac[i]=mr[i];
        i++;


    }
    printf("\n\n");
    display(mr,ho,ac,j,h);
}