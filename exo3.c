#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_arr(int *arr, int length_arr)
{
    for(int i = 0; i < length_arr; i++)
    {
        arr[i] = i + 1;
    }
}

void display_arr(int *arr, int length_arr)
{
    printf("[");
    for(int i = 0; i < length_arr; i++)
    {
        if(i == length_arr-1)
        {
            printf("%d]",arr[i]);
        }
        else
        {
            printf("%d,",arr[i]);
        }
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void applies_spec(int *arr, int N)
{
    int j = N-1;
    for(int i = 0; i < (N/2); i++)
    {
        swap(&arr[i],&arr[j]);
        j--;
    }
}

int error_handling_N(int N)
{
    if(N >= 0 && N <= 10)
    {
        return 1;
    }
    return 2; 
}

int main()
{
    int T[10];
    int N;
    printf("give a value in R & in [0,10] for N : ");
    scanf("%d",&N);
    while(error_handling_N(N) != 1)
    {
        printf("/!\\ give a value in R & in [0,10] for N : "); 
        scanf("%d",&N);
    }
    fill_arr(T,10);
    display_arr(T,10);
    applies_spec(T,N);
    display_arr(T,10);
    return 0;
}