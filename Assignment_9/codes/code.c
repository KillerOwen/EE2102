#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14159

//Write a function to generate a uniform distribution
double uniform(){
	double u1;
	while (1) {
	u1 = (( double )rand () / RAND_MAX );
	if (u1 > 0 && u1 < 1)
	break ;}
	return u1;	
}

//Write a function to generate a normal distribution by using the uniform distribution function defined above through box muller method
double normal(){
	double u1 = uniform();
	double u2 = uniform();

	double z1 = sqrt (-2 * log(u1)) * cos (2 *
	pi * u2);
	return z1;
}


int main(){
//Set the number of samples to be generated as 10000
int numsamples = 10000;

//Make a temoparary 2D array(dist) of size 2x10000 to store the values of Z_1 and Z_2 obtained after calling the normal distribution function
double dist[2][numsamples];

//Use a for loop to store the values obtained by calling the normal function multiple times 
for(int i=0;i<numsamples;i++){
dist[0][i] = normal();
dist[1][i] = normal();
}

//Assume the constants values, sigma_x = 0.5, sigma_y = 0.8, rho = 0.5, mu_x = 1, mu_y = 1.5
//Create A matrix and mu vector and fill the values assumed above in these, the dimension for matrix is 2x2 and the vector 1x2
double A[2][2] = {{0.5, 0},{0.4, 0.8*sqrt(0.75)}};
double u[2][1] = {1, 1.5};

//Create a vector z to store the values of Z_1 and Z_2 for a single iteration
double z[2][1];

//Make a 2D array(ans) to store the final values of x vector obtained after matrix multiplication
double ans[2][numsamples];

 
for(int i=0;i<numsamples;i++){
//For each iteration, assign values from one of the columns from dist to z vector 
z[0][0] = dist[0][i];
z[1][0] = dist[1][i];

//Store the values obtained from matrix multiplication in the ans array 
ans[0][i] = A[0][0]*z[0][0] + A[0][1]*z[1][0] + u[0][0];
ans[1][i] = A[1][0]*z[0][0] + A[1][1]*z[1][0] + u[1][0];

//The ans array has the values of vector x for 10000 simulations
printf("%lf %lf\n",ans[0][i],ans[1][i]);
}
return 0;
}
