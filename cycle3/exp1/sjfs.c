
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

#include "header.h"

void sort_sjfs(Process process[] ,int n ){
	for ( int i = 0 ; i< n-1 ; i++ ){
		int min = i ;
		for ( int j = i+1 ; j < n ; j++ ) {
			if ( process[min].burst > process[j].burst ) {
				Process  p = process[min] ; 
				process[min] = process[j] ; 
				process[j] = p ; 
			}
		}
	}
	
}

void sjfs(Process process[] , int n ){
	Process p[n] ; 
	for ( int i = 0 ; i < n ; i++ ){
		p[i] = process[i] ; 
	}
	Gantt gantt[n] ;
	sort_sjfs(p,n) ;
	producesGantt(p, gantt , n) ; 
	
	printGantt(gantt,n) ;
	findAll(p,gantt,n) ; 
	printProcess(p, n) ;

	printf("Average waiting time = %lf\n" ,avgWaiting(p, n)) ; 
	printf("Average TurnAround time = %lf\n" ,avgTAT(p, n)) ; 
	printf("Throughput  = %.3f",throughput(p,n)) ;

}

double throughput(Process process[] , int n ){
	int throughput = 0 ; 
	for ( int i = 0 ; i < n ; i++ )
		throughput += process[i].burst ; 
	return (double) n / (double) throughput ; 
}

