#ifndef SCHEDULING_H
#define SCHEDULING_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

typedef struct{
	int no; 
	int burst ; 
	int arrival ; 
	int waiting; 
	int turnaround ; 
}Process ;

typedef struct{
	int no ; 
	int start ; 
	int end ; 
}Gantt ; 

void printProcess(Process process[] , int n) ;
void printGantt(Gantt gantt[] , int n ) ;
void producesGantt(Process process[], Gantt gantt[], int n) ;
void findAll(Process process[], Gantt gantt[], int n) ;
double avgWaiting(Process process[], int n) ;
double avgTAT(Process process[], int n) ; 
void fcfs() ;
void sjfs() ; 


#endif //SCHEDULING_H