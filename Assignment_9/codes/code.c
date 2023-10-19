#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14159

double rv1() {
	double u1 , u2;
	while (1) {
	u1 = (( double )rand () / RAND_MAX );
	if (u1 > 0 && u1 < 1)
	break ;}
	while (1) {
	u2 = (( double )rand () / RAND_MAX );
	if (u2 > 0 && u2 < 1)
	break ;}

	double z1 = sqrt (-2 * log(u1)) * cos (2 *
	pi * u2);
	return z1;
}

double rv2() {
	double u1 , u2;
	while (1) {
	u1 = (( double )rand () / RAND_MAX );
	if (u1 > 0 && u1 < 1)
	break ;}
	while (1) {
	u2 = (( double )rand () / RAND_MAX );
	if (u2 > 0 && u2 < 1)
	break ;}

	double z2 = sqrt (-2 * log(u1)) * sin (2 *
	pi * u2);
	return z2;
}

int main(){

int numsamples = 10000;
double dist[2][numsamples];

for(int i=0;i<numsamples;i++){
dist[0][i] = rv1();
dist[1][i] = rv2();
}

//let sigma_x = 0.5, sigma_y = 0.8, rho = 0.5, mu_x = 1, mu_y = 1.5
double A[2][2] = {{0.5, 0},{0.4, 0.8*sqrt(0.75)}};
double z[2][1];

double u[2][1] = {1, 1.5};

double ans[2][numsamples];

for(int i=0;i<numsamples;i++){
z[0][0] = dist[0][i];
z[1][0] = dist[1][i];
//X
ans[0][i] = A[0][0]*z[0][0] + A[0][1]*z[1][0] + u[0][0];
//Y
ans[1][i] = A[1][0]*z[0][0] + A[1][1]*z[1][0] + u[1][0];

printf("%lf %lf\n",ans[0][i],ans[1][i]);
}
//fill in the values in the above arrays to get values of rv x


return 0;
}
