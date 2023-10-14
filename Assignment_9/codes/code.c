#include<stdio.h>
#include<math.h>

int main(){

int A[2][2];
int z[2][1];

int u[2][1];

int x[2][1];

//X
x[0][0] = A[0][0]*z[0][0] + A[0][1]*z[1][0] + u[0][0];
//Y
x[1][0] = A[1][0]*z[0][0] + A[1][1]*z[1][0] + u[1][0];

//fill in the values in the above arrays to get values of rv x

return 0;
}
