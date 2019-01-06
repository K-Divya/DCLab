//Write a program to print all the letters of the alphabet A- Z using threads.

#include<omp.h>
#include<stdio.h>

void main() 
{
	int i;
	#pragma omp parallel for num_threads(8)
	for(i = 97; i<=122; i++)
	    printf("%c",i);
    	printf("\n");
}
