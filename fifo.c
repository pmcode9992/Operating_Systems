#include<stdio.h>

int s = 3;

void display(int mem[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",mem[i]);
    }
    printf("\n");
}

int search(int c,int mem[], int size){
    for(int i=0;i<size;i++){
        if(c==mem[i]){
            return i;
        }
    }
    return 0;
}
int notin(int c,int mem[],int size){
    for(int i=0;i<c;i++){
        if(c==mem[i]){
            return 0;
        }
    }
    return 1;
}

int initial(int mem[],int arr[],int size, int n){
    int o=0,c=0;
    while(o!=3){
        if(c>=n){
            display(mem,size);
            return -1;
        }
        if(notin(arr[c],mem,size)){
            mem[o]=arr[c];
            o++;
        }
        c++;
    }
    display(mem,size);
    return c;
}

int maximum(int time[],int size){
    int max=-1,maxi=-1;
    for(int i=0;i<size;i++){
        if(max<time[i]){
            max=time[i];
            maxi=i;
        }
    }
    time[maxi]=0;
    return maxi;
}
void fifo(int arr[],int n){
    int pf=0;
    int mem[s];
    int time[3]={3,2,1};
    int i = initial(mem,arr,s,n);
    printf("After initial step\n");
    if(i==-1){
        i=n;
    }
    for(int j=i;j<n;j++){
        if(notin(arr[j],mem,s)){
            mem[maximum(time,s)]=arr[j];
            pf++;
        }
        else{
            int ti=search(arr[j],mem,s);
            time[ti]++;
        }
        display(mem,s);
    }
    printf("Page fault rate = %d",pf + s);
}
int main()
{
    int n;
    printf("Enter length of page of reference string : ");
    scanf("%d",&n);
    printf("\n Enter reference string : ");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    fifo(arr,n);
    return 0;
}