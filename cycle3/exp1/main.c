#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

#include "header.h"




int main(){
	int choice = 0 ; 
	
	do{
		printf("\n1. FCFS   2.SJFS   0. Exit \n >> ") ; 
		scanf("%d",&choice) ; 
		
		switch(choice){
			case 1: fcfs() ; 
				break ; 
			case 2: sjfs() ; 
				break ; 
			case 0: break; 

			default:
				printf("Invalid Entry !\n") ; 
		}
	}while(choice != 0 ) ; 
}

