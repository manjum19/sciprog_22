#include<stdio.h>
#include<math.h>
// Program to calculate the area under a curve by Trapezodial rule

int main(void){
int i, N=12;                         
float a = 0.0, b_deg = 60.0,b,area;

//Convert the degree to radian as function tan takes radian as input
b  = (b_deg*M_PI)/180.0;

printf("Value of b in radians is %f\n",b); 
// M_PI is a constant in C, it is equal to pi
printf("pi/3 in radians is : %f\n",b);
//Initialise the area for x0 and x12 the points
area = tan(a) + tan(b);

for(i= 5;i<60;i=i+5)
{                   
	//from 0 to 60 degree with bin size 5 since N=12
	area = area + 2 * tan((i*M_PI)/180.0);
}

area = ((b-a)/(2*N))*area;
printf("The area we got from the approximation is %f while the exact area is %f\n",area,log(2.0));
return 0;
}


