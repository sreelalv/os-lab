#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include "srtf.h"

void readProcess(Process process[] , int n){

	printf("Please Enter the burst time of the processes \n") ; 
	for ( int i = 0 ; i < n ; i++ ) {
		printf("process %d : ",i+1 ) ; 
		scanf("%d",&process[i].burst) ; 
		process[i].remaining = process[i].burst ; 
		process[i].no = i+1 ;
	}
	printf("Please Enter the arrival time of the processes \n") ; 
	for ( int i = 0 ; i< n ; i++ ) {
		printf("process %d : ",i+1 ) ; 
		scanf("%d",&process[i].arrival) ; 
	}
}


int main(){
	int choice = 0 ; 

	int n ; 
	printf("Enter the no of process : " ) ; 
	scanf("%d",&n ) ; 
	Process	process[n] ; 
	readProcess(process,n ) ;
	
	
	do{
		printf("\n\n1.SJFS  2.SRTF	3.readProcesses  0.Exit \n >> ") ; 
		scanf("%d",&choice) ; 
		
		switch(choice){
			case 1: sjfs(process,n) ; 
				break ;  
			case 2: srtf(process,n) ; 
				break ;  
			case 3:	printf("Enter the no of process : " ) ; 
				scanf("%d",&n ) ; 
				readProcess(process,n ) ;
			case 0: break; 
			default:
				printf("Invalid Entry !\n") ; 
		}
	}while(choice != 0 ) ; 
	return 0 ;
}

