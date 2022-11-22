#include <stdio.h>
#include <stdlib.h>

//Takes an integer as an argument and returns a pointer to an allocated memory block of that many integers
int *allocatearray(int n)
{
    int *p;
    p=(int *) malloc((n)*sizeof(int));
    return p;
}

//Takes a pointer to an array of integers and fills every cell of the array with a one
void fillwithones(int *array, int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        array[i] = 1;
    }
}

//Takes a pointer to an array of integers and prints its elements on screen
void printarray(int *array, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("a[%d]=%d\n",i,array[i]);
    }
}

//Free allocated memory
void freearray(int *array)
{
    free(array);
}

int main()
{
    int length, *a;
    printf("\nEnter the size of the array: \n");
    scanf("%d",&length);

    a = allocatearray(length);
    fillwithones(a,length);
    printarray(a,length);
    freearray(a);
    a=NULL;
    return 0;
}

