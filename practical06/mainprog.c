#include <stdio.h>
#include <stdlib.h>

//In this file we will call another function matmult to perform the matrix multiplication on 2 matrices A and B 

int main(void)
{

    //Declaring the dimensions of the matrices
    int n=5, p=3, q=4;
    //Declaring the matrices of fixed size
    double A[n][p], B[p][q], C[n][q];
    //Declaring the loop indices
    int i,j,k; 

    // Matrix A
    for (i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
        {
            A[i][j] = i + j;
        }
    }

    // Matrix B
    for (i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            B[i][j] = i - j;
        }
    }

    // Matrix C
    for (i=0;i<n;i++)
    {
        for(j=0;j<q;j++)
        {
            C[i][j] = 0.0;
        }
    }

    //Calling the matrix multiplication function
    matmult(n,p,q,A,B,C);

    // Printing the Matrices
    printf("\nMatrix A:\n");
    for (i=0;i<n;i++)
    {
        for(j=0;j<p;j++)
        {
            printf("%3.0f ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%3.0f ", B[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix C:\n");
    for (i=0;i<n;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%3.0f ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}

