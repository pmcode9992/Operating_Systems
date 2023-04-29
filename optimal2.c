#include<stdio.h>
int main()
{
    int size, n, mem[10], arr[30], temp[10], f1, f2, flag3, i, j, k, pos, max, pf = 0;
    printf("Enter number of frames: ");
    scanf("%d", &size);
    
    printf("Enter number of pages: ");
    scanf("%d", &n);
    
    printf("Enter reference string: ");
    
    for(i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    
    for(i = 0; i < size; ++i){
        mem[i] = -1;
    }
    
    for(i = 0; i < n; ++i){
        f1 = f2 = 0;
        
        for(j = 0; j < size; ++j){
            if(mem[j] == arr[i]){
                   f1 = f2 = 1;
                   break;
               }
        }
        
        if(f1 == 0){
            for(j = 0; j < size; ++j){
                if(mem[j] == -1){
                    pf++;
                    mem[j] = arr[i];
                    f2 = 1;
                    break;
                }
            }    
        }
        
        if(f2 == 0){
         flag3 =0;
        
            for(j = 0; j < size; ++j){
             temp[j] = -1;
            
             for(k = i + 1; k < n; ++k){
             if(mem[j] == arr[k]){
             temp[j] = k;
             break;
             }
             }
            }
            
            for(j = 0; j < size; ++j){
             if(temp[j] == -1){
             pos = j;
             flag3 = 1;
             break;
             }
            }
            
            if(flag3 ==0){
             max = temp[0];
             pos = 0;
            
             for(j = 1; j < size; ++j){
             if(temp[j] > max){
             max = temp[j];
             pos = j;
             }
             }            
            }
mem[pos] = arr[i];
pf++;
        }
        
        printf("\n");
        
        for(j = 0; j < size; ++j){
            if(mem[j]!=-1)
            {printf("%d ", mem[j]);}
        }
    }
    
    printf("\n\nTotal Page Faults = %d", pf);
    
    return 0;
}