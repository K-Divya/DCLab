/*There are two arrays A and B write a program that has two blocks: one for generating array C = A+B
and another array D = A*B, such that work in blocks will be done by different threads*/

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

void main() {

    int a[100],b[100],c[100],d[100];
    int i;
    
    for(i=0;i<100;i++)
        a[i] = b[i] = i*2;
        
    #pragma omp parallel num_threads(4)
    {
        int tid = omp_get_thread_num();
        int j;
        #pragma omp sections
        {
        	#pragma omp section
        	{
        	    printf("Thread %d executing section 1 \n",omp_get_thread_num());
        	    for(j=0;j<100;j++) 
    	            	c[j] = a[j] + b[j];
    	       	}
        	#pragma omp section
        	{
        	    printf("Thread %d executing section 2  \n",omp_get_thread_num());
        	    for(j=0;j<100;j++) 
    	            	d[j] = a[j] * b[j];
    	        }
        }
    }
    for(i=0;i<100;i++)
        printf("%d %d\n",c[i],d[i]);
}
