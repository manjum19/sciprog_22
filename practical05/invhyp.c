#include<stdio.h>
#include<math.h>

// In this practical we implement the inverse hyperbolic tangent by 2 methods

//The first function uses the Maclaurin series
double arctanh1(const double x, const double delta);
//The second function uses natural log
double arctanh2(const double x);

int main()
{
	double delta,x;
	printf("Enter the precision delta for Maclaurin Series: \n"); //We need a stopping point delta
	scanf("%lf", &delta);
	
	int length = 1000;
	double hyptan1[length]; // Store the results of arctanh1 for each x
	double hyptan2[length]; //Store the results of arctanh2 for each x


	int i=0;
	x = -0.9;
	while(x<=0.9 && i<length)
	{
		hyptan1[i] = arctanh1(x,delta);
		hyptan2[i] = arctanh2(x);
		printf("The difference at x=%lf is %.10lf\n",x,fabs(hyptan1[i]-hyptan2[i]));
		i++;
		x=x+0.1; 
	}
	return 0;
}

//Maclaurin Method
double arctanh1(const double x, const double delta){
	double arc = 0;  
	double elem, val;
	int n=0; 
	
	do {	
		val = 2*n+1;
		elem = pow(x,val)/val;
		arc+=elem;
		n++;

	} while(fabs(elem) >= delta); // this returns absolute value of the float
	return arc;
} 

//Natural log Method
double arctanh2(const double x)
{
	return (log(1+x)-log(1-x)/2);
}

