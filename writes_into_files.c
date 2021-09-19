#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void reads_into_file(FILE *file_pointer)
{
    char c;
    while((c = fgetc(file_pointer)) != EOF)
    {
        printf("%c",c);
    }
}

void writes_into_file(FILE *file_pointer)
{
    int i = 0;
    char c;
    scanf("%c",&c);
    while(i < MAX && c != '|')
    {
        fputc(c,file_pointer);
        i++;
        scanf("%c",&c);
    }
}

int main()
{
    char *file_name = "f.txt";
    FILE *file_pointer = fopen(file_name,"r");
    file_pointer = fopen(file_name,"w");
    if(file_pointer == NULL)
    {
        printf("error : could not open %s\n",file_name);
        exit(1);
    }
    printf("character limit = %d, type \"|\" followed by the ENTER key to stop typing.\n",MAX);
    printf("/!\\ you will not append but overwrite, enter what you wish to write into f.txt :\n\n");
    writes_into_file(file_pointer);
    fclose(file_pointer);
    printf("\nWhat you wrote into %s is :\n\n",file_name);
    file_pointer = fopen(file_name,"r");    
    reads_into_file(file_pointer);
    fclose(file_pointer);
    printf("\n");
    return 0;
}