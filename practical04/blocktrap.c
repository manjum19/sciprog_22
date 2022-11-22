#include<stdio.h>
#include<math.h>


// Function used to convert degrees to radians
float deg_to_rad(float deg)
{
	return(M_PI* deg / 180.0);
}

// function to calculate area using the trapezoidal rule
float trap_rule(float a, float b, int N, float function_array[N+1])
{
	float sum = function_array[0] + function_array[N];
	int i =0;
	for(i=1;i<N;i++)
	{
		sum+= 2*function_array[i];
	}
	return (b-a)*(sum)/(2*N);
}

int main(void){
	float start = 0;
	float end = 60;
	int N = 12;
	float step_size = (end-start)/N;
	float tan_arr[N+1];
	
	int i = 0;
	for (i=0; i<N; i++)
	{
		// calling function deg_to_rad 
		tan_arr[i] = tan(deg_to_rad(step_size*i));
	}
	// calling the function trap_rule 
	float ans = trap_rule(deg_to_rad(start),deg_to_rad(end),N,tan_arr);
	printf("The answer is %f\n",ans);
	printf("The actual answer is %f\n",log(2.0));
	return 0;
}

