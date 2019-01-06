//Write a program to find the largest element in an array (usage of locks)

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

void main() {
	omp_lock_t lock;
	int max_p = 0,max_s = 0;
	int i,a[100];
	
	for(i=0;i<100;i++) 
	    a[i] = rand()%1000;
	
	printf("Checking max through parallel\n");
	omp_init_lock(&lock);
	#pragma omp parallel for num_threads(4)
	for(i=0;i<100;i++) 
	    if(a[i]>max_p) {
	        omp_set_lock(&lock);
	        max_p = a[i];
	        omp_unset_lock(&lock);
	    }
	omp_destroy_lock(&lock);
	
	printf("Checking max through serial\n");
	for(i=0;i<100;i++) {
	    if(a[i]>max_s)
	        max_s = a[i];
	}
	printf("Parallel max %d serial max %d\n",max_p,max_s);
}
