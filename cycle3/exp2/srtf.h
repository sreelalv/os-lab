#ifndef _SRTF_
#define _SRTF_

#include<stdbool.h>
#include<limits.h>

typedef struct{
	int no; 
	int burst ;    
    int arrival ; 
	int waiting; 
	int turnaround ;
    int remaining ;  
}Process ;

typedef struct Gantt {
    int no ; 
    int start ; 
    int end ; 
    struct Gantt* next ; 
}Gantt ;


void readProcess(Process[],int) ;
void printGantt(Gantt*) ;
void printProcess(Process[] , int) ;

double avgWaiting(Process[], int) ;
double avgTAT(Process[], int) ; 
double throughput(Process[], int) ; 

void srtf(Process[] , int) ;
void sjfs(Process[] , int) ;

void sort(Process[] ,int ,bool) ;
void swap(Process* , Process*) ;

Gantt* producesGantt(Process[] , int , bool);
Gantt* newGantt() ;

#endif // _SRTF_
