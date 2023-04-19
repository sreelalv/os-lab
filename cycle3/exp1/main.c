#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

#include "header.h"

int main(){
	int choice = 0 ; 

	int n ; 
	printf("Enter the no of process : " ) ; 
	scanf("%d",&n ) ; 
	Process	process[n] ; 
	readProcess(process,n ) ;
	
	
	do{
		printf("\n\n1.FCFS	2.SJFS	3.readProcesses  0.Exit \n >> ") ; 
		scanf("%d",&choice) ; 
		
		switch(choice){
			case 1: fcfs(process,n) ; 
				break ; 
			case 2: sjfs(process,n) ; 
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

