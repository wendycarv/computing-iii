#include <stdio.h>

void select_sort(int N);

int main(int argc, char* argv[])
{
    select_sort(6);

    return 0;
}

void select_sort (int N)
{
    int i, j, min, max, tmp;
    int A[6] = {1,5,8,6,7,2};
    for (i = 0; i < N ; i++)
    {
        min = i;
        max = i;
        for (j = i+1; j <= N-i; j++)
        {
            
            if (A[j] > A[max])
            {
                max = j;
                
            }
             
            if (A[j] < A[min])
            {
                min = j;
                
            }
            
            tmp = A[i - 1];
            A[i - 1] = A[min];
            A[min] = tmp;
            tmp = A[N - i];
            A[N - i] = A[max];
            A[max] = tmp;
           
        }
   
    }
    
    for(i = 0; i < N; i++)
    {
        printf("A[%d]: %d \n", i, A[i]);
    }
}

