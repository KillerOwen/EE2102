import numpy as np

A = np.array([1,-1])
print("Point A is : ",A)
D = np.array([-3.5,0.5])
print("Mid point of BC(D) is : ",D)

m = D-A
print("m = ",m)

nt = np.array([m[1],-m[0]])
print("n^T = ",nt)

#proof for nt.m = 0
value = nt[0]*m[0] + nt[1]*m[1] 
print("Value of n^T.m = ",value)

#calculation of constant we get on multiplying n^T and A
nt = nt*2
#the above step is done to cancel out the factor of 1/2 on both sides of equation

const = nt[0]*A[0] + nt[1]*A[1]
print("Value of n^T.A = ",const)
