#include<stdio.h>
#include<limits.h>

int faultcheck(int incomingPage, int queue[], int o){
    
    for(int i = 0; i < o; i++){
        if(incomingPage == queue[i])
            return 1;
    }
    
    return 0;
}
void display(int mem[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",mem[i]);
    }
    printf("\n");
}
int main()
{

    int arr[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};
    
    int n = sizeof(arr)/sizeof(arr[0]);
    int size  = 3;
    int queue[n];
    int time[n];
    int o = 0;
    int pf = 0;
    
    printf("Page F1 F2 F3\n");
    
    for(int i = 0;i < n; i++)
    {
        printf("%d: ",arr[i]);

        
        if(faultcheck(arr[i], queue, o)){
            display(queue, o);
        }
        
        // filling when frame(s) is/are empty
        else if(o < size ){
            queue[o] = arr[i];
            pf++;
            o++;
            
            display(queue, o);
        }
        else{
            
            int max = INT_MIN;
            int index;
            for (int j = 0; j < size ; j++)
            {
                time[j] = 0;

                for(int k = i - 1; k >= 0; k--)
                {
                    ++time[j];

                    if(queue[j] == arr[k])
                        break;
                }
                
                if(time[j] > max){
                    max = time[j];
                    index = j;
                }
            }
            queue[index] = arr[i];
            display(queue, o);
            pf++;
        }
        
        printf("\n");
    }
    
    printf("Page Fault: %d",pf);
    
    return 0;
}