#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// In this practical, we print the fibonacci series

void fibonacci(int *a, int *b);

int main()
{
	int n,i;
	//The first 2 numbers of the fibonacci are used as constants to trigger the rest of the sequence
	int f1=1,f0=0;
	
	printf("Enter a positive integer n:\n");
	scanf("%d", &n);
	
	if (n<1)
	{
		printf("The number must be positive\n");
		exit(1);
	}
	printf("The fibonacci sequence is %d, %d ,", f0, f1);

	for (i=2;i<n;i++)
	{
		// The next number is equal to the sum of the previous 2 numbers of the sequence
		fibonacci(&f0, &f1);
		
		if(i == n-1) 
			printf("%d ", f1);
		else
			printf("%d, ", f1);
		
		// To break the line after 10 terms
		if (((i+1)%10)==0) 
			printf("\n");
	}
	return 0;
}
	
void fibonacci(int *a, int *b)
{
	int next;
	next = *a+*b;
	*a = *b;
	*b = next;
}

