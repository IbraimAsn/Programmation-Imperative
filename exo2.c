#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void fill_array(int *arr, int length_arr)
{
    for(int i = 0; i < length_arr; i++)
    {
        printf("give a value for arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
}

int checks_if_palindrome(int *arr, int length_arr)
{
    int i = 0, j = length_arr - 1;
    while(arr[i] == arr[j] && i < j)
    {
        i++;
        j--;
    }
    if(i >= j)
    {
        return 0;
    }
    return 1;
}

void displays_arr(int *arr, int length_arr)
{
    if(length_arr != 0)
    {
        printf("[");
        for(int i = 0; i < length_arr; i++)
        {
            if(i != length_arr -1)
                printf("%d,",arr[i]);
            else
                printf("%d] : ",arr[i]);
        }
    }
}

void tells_if_palindrome(int my_bool)
{
    if(my_bool == 0)
        printf("est un palindrome\n");
    else
        printf("n'est pas un palindrome\n"); 
}

int length_arr_handling(int length_arr)
{
    if(length_arr < 0 || length_arr > MAX)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int length_arr;
    printf("length of array (has to be a real number in [0,10]) : ");
    scanf("%d",&length_arr);
    while(length_arr_handling(length_arr) != 0)
    {
        printf("length of array (has to be a real number in [0,10]) : ");
        scanf("%d",&length_arr);
    }
    printf("\n");
    int *arr = malloc(sizeof(int)*length_arr);
    fill_array(arr,length_arr);
    printf("\n");
    displays_arr(arr, length_arr);
    tells_if_palindrome(checks_if_palindrome(arr,length_arr));
    free(arr);
    return 0;
}