#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tells_if_digit(char c)
{
    if((int)c >= 48 && (int)c <= 57)
        return 1;
    return 0;
}

int get_amount_numbers(FILE *file_pointer)
{
    int counter_numbers = 0;
    char previous_char, current_char;
    while((current_char = fgetc(file_pointer)) != EOF)
    {
        if(tells_if_digit(current_char) == 1)
        {
            if(counter_numbers == 0)
            {
                counter_numbers++;
            } 
            else if(tells_if_digit(previous_char) != 1)
            {
                counter_numbers++;
            }
        }
        previous_char = current_char;
    }
    return counter_numbers;
}

void add_numbers_to_arr(FILE *file_pointer, int *arr, int length_arr)
{
    char c;
    int i = 0, sum = 0, checker = 0;
    while((c = fgetc(file_pointer)) != EOF)
    {
        if(tells_if_digit(c))
        {
            if(checker == 0)
            {
                checker++;
            }
            sum = sum * 10 + (int)c - 48;
        }
        else if(checker != 0)
        {
            arr[i] = sum;
            i++;
            sum = 0;
            checker = 0;
        }
    }
    if(checker != 0)
    {
        arr[length_arr-1] = sum;
    }
}

void displays_arr(int *arr, int length_arr)
{
    for(int i = 1; i < length_arr+1; i++)
    {
        if(i != 0 && i % 3 == 0 && i != length_arr)
        {
            printf("%d\n",arr[i-1]);
        }
        else
        {
            printf("%d\t",arr[i-1]);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    FILE *file_pointer = fopen(argv[1],"r");
    if(file_pointer == NULL)
    {
        printf("error : could not open %s\n",argv[1]);
        exit(1);
    }
    int length_arr = get_amount_numbers(file_pointer);
    int *arr = malloc(sizeof(int)*length_arr);
    fclose(file_pointer);
    file_pointer = fopen(argv[1],"r");
    add_numbers_to_arr(file_pointer,arr,length_arr);
    printf("# of numbers : %d\n\n",length_arr);
    displays_arr(arr,length_arr);
    free(arr);
    fclose(file_pointer);
    return 0;
}