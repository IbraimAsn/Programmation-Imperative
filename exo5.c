#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ask_for_matrix_dimensions(int *dimensions_matrix, int matrix_nbr)
{
    for(int i = 0; i < 2; i++)
    {
        if(i == 0)
        {
            printf("# of rows for Matrix%d: ",matrix_nbr);
        }
        else
        {
            printf("# of columns for Matrix%d: ",matrix_nbr);
        }     
        scanf("%d",&dimensions_matrix[i]);
    }
}

void initialize_matrix(int **matrix, int nbr_rows, int nbr_columns)
{
    for(int i = 0; i < nbr_rows; i++)
    {
        matrix[i] = malloc(sizeof(int)*nbr_columns);
    }
}

void fill_matrix(int **matrix, int nbr_rows, int nbr_columns)
{
    for(int i = 0; i < nbr_rows; i++)
    {
        for(int j = 0; j < nbr_columns; j++)
        {
            matrix[i][j] = rand()%10;
        }
    }
}

void display_matrix(int **matrix, int nbr_rows, int nbr_columns)
{
    for(int i = 0; i < nbr_rows; i++)
    {
        printf("\t[");
        for(int j = 0; j < nbr_columns; j++)
        {
            if(j == nbr_columns-1)
            {
                printf("%d",matrix[i][j]);
            }
            else
            {
                printf("%d,",matrix[i][j]);
            }
        }
        printf("]\n");
    }
}

void free_matrix(int **matrix, int nbr_rows)
{
    for(int i = 0; i < nbr_rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void multiply_matrices(int **matrix0, int *dimension_matrix0, int **matrix1, int *dimension_matrix1, int **matrix2)
{
    int i = 0, j = 0, k = 0;
    int result = 0;
    while(i < dimension_matrix0[0])
    {
        while(k < dimension_matrix1[1])
        {
            result += matrix0[i][j] * matrix1[j][i+k];
            j++;
            if(j >= dimension_matrix1[0])
            {
                matrix2[i][k] = result;
                j = 0;
                result = 0;
                k++;
            }
        }
        i++;
        k = 0;
    }
}

int main()
{
    srand(time(NULL));
    int dimensions_matrix0[2], dimensions_matrix1[2];
    ask_for_matrix_dimensions(dimensions_matrix0,0);
    printf("\n");
    ask_for_matrix_dimensions(dimensions_matrix1,1);
    if(dimensions_matrix0[1] != dimensions_matrix1[0])
    {
        printf("error : nbr of rows for matrix0 != from nbr of columns for matrix1\n");
        exit(1);
    }
    int **matrix0 = malloc(sizeof(int*)*dimensions_matrix0[0]);
    int **matrix1 = malloc(sizeof(int*)*dimensions_matrix1[0]);
    int **matrix2 = malloc(sizeof(int*)*dimensions_matrix0[0]);
    initialize_matrix(matrix0,dimensions_matrix0[0],dimensions_matrix0[1]);
    initialize_matrix(matrix1,dimensions_matrix1[0],dimensions_matrix1[1]); 
    initialize_matrix(matrix2,dimensions_matrix0[0],dimensions_matrix1[1]); 
    fill_matrix(matrix0,dimensions_matrix0[0],dimensions_matrix0[1]);
    fill_matrix(matrix1,dimensions_matrix1[0],dimensions_matrix1[1]);
    printf("\nMatrix%d:\n",0);
    display_matrix(matrix0,dimensions_matrix0[0],dimensions_matrix0[1]);
    printf("\n");
    printf("Matrix%d:\n",1);
    display_matrix(matrix1,dimensions_matrix1[0],dimensions_matrix1[1]);
    multiply_matrices(matrix0,dimensions_matrix0,matrix1,dimensions_matrix1,matrix2);
    printf("\nMatrix%d * Matrix%d:\n",0,1);
    display_matrix(matrix2,dimensions_matrix0[0],dimensions_matrix1[1]);
    free_matrix(matrix0,dimensions_matrix0[0]);
    free_matrix(matrix1,dimensions_matrix1[0]);
    free_matrix(matrix2,dimensions_matrix0[0]);
    return 0;
}