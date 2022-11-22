#include <stdio.h>
#include <stdlib.h>
#include "magic_square.h"
#define MAX_FILE_NAME 100

//In this file, we read the matrix from a file, and use magic_square.h to determin if our matrix is a magic square or not

//This function reads a file and detects the number of lines
int get_num_lines(char filename[MAX_FILE_NAME])
{
    FILE *fp;
    fp = fopen(filename, "r");
    int ch_read;
    int count = 0;
    while ((ch_read = fgetc(fp))!= EOF)
    {
        if (ch_read == '\n')
        {
            count++;
        }
    }
    printf("Number of lines is : %d\n",count);
    fclose(fp);
    return count;
}

int main(void)
{
    FILE *f;
    char filename[MAX_FILE_NAME];
    printf("Enter file name please: ");
    scanf("%s",filename);

    //Computer number of lines in the file which will be the dimension of our matrix
    int n = get_num_lines(filename);

    f = fopen(filename, "r");

    int i;
    int **magicsquare = malloc((n)*sizeof(int *));
    for (i=0;i<n;i++)
    {
        magicsquare[i] = malloc(n*sizeof(int));
    }
    int j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
            {
                fscanf(f,"%d",&magicsquare[i][j]);
            }
    }
    //Call external function to determine if matrix is a magic square, passing the matrix and the dimension
    int flag = isMagicSquare(magicsquare,n);
    if (flag==1)
    {
        printf("This square is magic\n");
    }
    else
    {
        printf("This square is not magic\n");
    }

    for (i=0;i<n;i++)
    {
        free(magicsquare[i]);
    }
    free(magicsquare);
    fclose(f);
    return 0;
}

