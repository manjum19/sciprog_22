#include <stdio.h>

//In this program, we find the  greatest common divisor of 2 numbers through 2 methods: the Eucilidean algorithm or through iteration

int iterativeGCD(int a, int b);
int recursiveGCD(int a, int b);

int main()
{

    int x, y, ierror;
    printf("Enter the two positive integers: \n");    
    ierror = scanf("%d %d", &x,&y);
    if (ierror!=2)
    {
        printf("Please enter two integers!\n");
        return 1;
    }
    // Check if the numbers entered are positive.
    if (x<=0 || y<=0)
    {
        printf("These numbers are not positive!\n");
        return 1;
    }
    printf("The Greatest Common Divisor of %d and %d using iterative function is : %d\n", x,y,iterativeGCD(x,y));
    printf("The Greatest Common Divisor of %d and %d using recursive function is : %d\n", x,y,recursiveGCD(x,y));
    return 0;
}

//Finding the GCD through iteration
int iterativeGCD(int a, int b)
{
    int temp;
    while((b!=0))
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

//Finding the GCD through recursion
int recursiveGCD(int a, int b)
{
    if (b==0)
    {
        return a;
    }
    else 
    {
        return(recursiveGCD(b,a%b));
    }
}

