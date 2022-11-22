#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//In this function we will calculate e using the Taylor series expansion 

int factorial(int n);

int main(void)
{
    int i, order;    
    double e, *terms;
   
    // Enter the polynomial order
    printf("Enter the required polynomial order\n");
    if (scanf("%d", &order) != 1)
    {
        printf("Warning : Enter an integer number");
        return 1;
    }

    //Allocate space for terms array
    terms = malloc(order*sizeof(double));// malloc used for dynamic memory allocation

    for(i=0;i<order;i++)
    {
        terms[i] = 1.0/(double)factorial(i+1);
        printf("\ne term for order %d is %1.14lf\n", order, terms[i]);
    }
    e = 1.0;
    for (i=0;i<order;i++)
    {
        e = e + terms[i];
    }
    free(terms);
    printf("\ne is estimated to be %.10lf, with a difference %.10lf. \n", e, e-exp(1.0));
    return 0;
}

int factorial(int n)
{
    if (n<0)
    {
        printf("Error : n must be positive.");
        return(-1);
    }
    else if (n==0)
    {
        return 1;
    }
    else
    {
        //recursion
        return(n*factorial(n-1)); 
    }
}

