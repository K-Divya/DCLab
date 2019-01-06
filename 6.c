//Write a program to find the largest element in an array

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
void main() {
	int max_p = 0,max_s = 0;
	int i,a[100];
	
	for(i=0;i<100;i++) 
	    a[i] = rand()%1000;
	
	printf("Checking max through parallel\n");
	#pragma omp parallel for num_threads(8)
	for(i=0;i<100;i++) 
	    if(a[i]>max_p) 
	    	#pragma omp critical
	    	max_p = a[i];
	    
	printf("Checking max through serial\n");
	for(i=0;i<100;i++) {
	    if(a[i]>max_s)
	        max_s = a[i];
	}
	printf("Parallel max %d serial max %d\n",max_p,max_s);
}
