#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE 2147483647 // also known as 2.147483647 GB

int convert_chars_into_num(char c)
{
    if((int)c >= 48 && (int)c <= 57)
    {
        return (int)c - 48;
    }
    return -1;
}

/*void allocates_memory_for_array(char *array_of_chars, int file_size)
{
    
}*/

int main(int argc, char *argv[])
{
    FILE *file_pointer = fopen(argv[1],"r");
    if(file_pointer == NULL)
    {
        printf("error : could not open %s\n",argv[1]);
        exit(1);
    }
    struct stat st;
    stat(argv[1], &st);
    off_t file_size = st.st_size;
    char *array_of_chars;
    //allocates_memory_for_array(array_of_chars,(int)file_size);
    printf("size of %s : %d\n",argv[1],(int)file_size);
    free(array_of_chars);
    fclose(file_pointer);
    return 0;
}   