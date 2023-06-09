#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

#include "header.h"


void printProcess(Process process[] , int n){
	printf("PROCESS CHART\n\n") ;
	printf("Process\t") ; 
	for ( int i = 0 ; i < n ; i++ )
		printf(" %3d ", process[i].no) ;

	printf("\nBurst\t") ;
	for ( int i= 0 ; i< n ; i++ )
		printf(" %3d ", process[i].burst) ; 

	printf("\nWaiting\t") ;
	for ( int i =0 ; i< n ; i++)
		printf(" %3d ", process[i].waiting) ;

	printf("\nTAT\t") ; 
	for ( int i= 0 ; i< n ; i++ ) 
		printf(" %3d ", process[i].turnaround) ;
	
	printf("\n\n") ;
}

void printGantt(Gantt gantt[] , int n ){
	printf("Gantt Chart \n") ; 
	for ( int i= 0  ; i< n 	  ; i++){
		printf("%2d : %2d : %2d \n",gantt[i].start, gantt[i].no , gantt[i].end ) ; 
	}	
	printf("\n") ;
}
void producesGantt(Process process[], Gantt gantt[], int n){
		gantt[0].no = process[0].no ; 
		gantt[0].start = 0 ; 
		gantt[0].end = process[0].burst ; 
		for ( int i = 1 ; i< n ; i++){
			gantt[i].no = process[i].no ; 
			gantt[i].start = gantt[i-1].end ; 
			gantt[i].end = gantt[i].start + process[i].burst ; 
		}		
}
void findAll(Process process[], Gantt gantt[], int n){
	for ( int i = 0 ; i < n ; i++ ){
		if ( process[i].no == gantt[i].no ){
			process[i].waiting = gantt[i].start ;  
			process[i].turnaround = process[i].burst + process[i].waiting ;
		}
	}
}

double avgWaiting(Process process[], int n){
	double avgWaiting =  0 ; 
	for ( int i = 0 ; i < n ; i++ ) {
		avgWaiting += process[i].waiting ; 
	}
	return (avgWaiting / n ) ; 
}

double avgTAT(Process process[], int n){
	double tat  = 0 ;
	for ( int i = 0 ; i < n ; i++ ){
		tat += process[i].turnaround ; 
	}
	return (tat / n ) ; 
}

	
void fcfs(Process process[], int n){
	Gantt gantt[n] ; 
	producesGantt(process, gantt , n) ; 
	
	printGantt(gantt,n) ;
	findAll(process,gantt,n) ; 
	printProcess(process, n) ;

	printf("Average waiting time = %lf\n" ,avgWaiting(process, n)) ; 
	printf("Average TurnAround time = %lf\n" ,avgTAT(process, n)) ; 
	printf("Throughput  = %.3f",throughput(process,n) );

}


void readProcess(Process process[] , int n){

	printf("Please Enter the burst time of the processes \n") ; 
	for ( int i = 0 ; i < n ; i++ ) {
		printf("process %d : ",i+1 ) ; 
		scanf("%d",&process[i].burst) ; 
		process[i].no = i+1 ;
	}
}
