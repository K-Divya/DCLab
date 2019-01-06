//Add two arrays A & B each of 1000 to generate an array C using reduction clause

#include<omp.h>
#include<stdio.h>

void main() {
	int a[1000],b[1000],c[1000],sum,i;
	for(i=0;i<100;i++)
	    a[i] = b[i] = i;
    	#pragma omp parallel for reduction(+:sum)
    	for(i=0;i<1000;i++) 
    	{
		sum = sum + a[i] + b[i];
		c[i] = sum; 
    	}
    	for(i=0;i<100;i++)
        	printf("%d\n",c[i]);
	printf("Sum %d \n",sum);
}
