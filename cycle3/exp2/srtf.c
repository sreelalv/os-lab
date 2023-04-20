#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


#include "srtf.h"

Gantt* newGantt(){
    return (Gantt*)malloc(sizeof(Gantt)) ; 
}

Gantt* producesGantt(Process processes[] , int n , bool preemptive){
    if ( ! preemptive ){
		Gantt *gantt = newGantt();
		Gantt *ptr = gantt ; 
		Gantt *pptr = ptr ; 
		
		sort(processes,n,false) ;
		ptr->no = processes[0].no ; 
		ptr->start = 0 ;   

        ptr->end = processes[0].burst ;  

        for ( int i = 1 ; i< n ; i++){
            ptr->next = newGantt() ;
            ptr = ptr->next ;
            
            ptr->no = processes[i].no ; 
            ptr->start = pptr->end ; 
            ptr->end = ptr->start + processes[i].burst ; 

            pptr = ptr ;
        }
		Gantt* pGantt  = gantt ;
		do{
			for ( int i = 0 ; i < n ; i++ ){
				if ( pGantt->no == processes[i].no ){
					processes[i].waiting = pGantt->start ;  
					processes[i].turnaround = processes[i].burst + processes[i].waiting ;
					pGantt = pGantt->next;
				}
			}	
		}while(pGantt != NULL );
    	return gantt;

    }else{ 
		int currentTime = 0;
		int completed = 0;
		Process* currentProcess = NULL;
		Gantt* ganttHead = NULL;
		Gantt* ganttTail = NULL;

		while (completed < n) {
			int shortestIndex = -1;
			int shortestTime = INT_MAX;
			for (int i = 0; i < n; i++) {
				if (processes[i].remaining > 0 && processes[i].arrival <= currentTime &&
					processes[i].burst < shortestTime) {
					shortestIndex = i;
					shortestTime = processes[i].burst;
				}
			}

			if (shortestIndex == -1) {
				currentTime++;
			} else {
				Process* shortestProcess = &processes[shortestIndex];
				shortestProcess->waiting = currentTime - shortestProcess->arrival;
				shortestProcess->turnaround = shortestProcess->waiting + shortestProcess->burst;

				if (ganttHead == NULL) {
					ganttHead = (Gantt*)malloc(sizeof(Gantt));
					ganttHead->no = shortestProcess->no;
					ganttHead->start = currentTime;
					ganttHead->end = currentTime + 1;
					ganttHead->next = NULL;
					ganttTail = ganttHead;
				} else {
					Gantt* ganttPtr = (Gantt*)malloc(sizeof(Gantt));
					ganttPtr->no = shortestProcess->no;
					ganttPtr->start = currentTime;
					ganttPtr->end = currentTime + 1;
					ganttPtr->next = NULL;
					ganttTail->next = ganttPtr;
					ganttTail = ganttPtr;
				}

				currentProcess = shortestProcess;
				currentProcess->remaining--;
				currentTime++;

				if (currentProcess->remaining == 0) {
					completed++;
					currentProcess = NULL;
				}
			}
		}
		return ganttHead;		
	}
}

void printGantt(Gantt *gantt){
    if(gantt == NULL )
        printf("There is some error in printing the gantt chart \n") ; 
    else{
        Gantt *ptr = gantt ; 
        do {
            printf("%2d : %2d : %2d \n",ptr->start, ptr->no, ptr->end ) ; 
            ptr = ptr->next ; 
        }while(ptr != NULL) ; 
    }
}

void swap(Process *x , Process *y){
	Process p = *x ; 
	*x = *y ; 
	*y = p ;
}

void sort(Process processes[] ,int n ,bool preemptive){
	for ( int i = 0 ; i< n-1 ; i++ ){
		int min = i ;
		for ( int j = i+1 ; j < n ; j++ ) {
			if ( ! preemptive ){
				if ( processes[min].burst > processes[j].burst )
					swap(&processes[min], &processes[j]) ;
			}else{
				if ( processes[min].arrival > processes[j].arrival )
					swap(&processes[min], &processes[j]) ; 
			}
		}
	}
	
}


double avgWaiting(Process processes[], int n){
	double avgWaiting =  0 ; 
	for ( int i = 0 ; i < n ; i++ ) {
		avgWaiting += processes[i].waiting ; 
	}
	return (avgWaiting / n ) ; 
}

double avgTAT(Process processes[], int n){
	double tat  = 0 ;
	for ( int i = 0 ; i < n ; i++ ){
		tat += processes[i].turnaround ; 
	}
	return (tat / n ) ; 
}
double throughput(Process processes[] , int n ){
	int throughput = 0 ; 
	for ( int i = 0 ; i < n ; i++ )
		throughput += processes[i].burst ; 
	return (double) n / (double) throughput ; 
}


void printProcess(Process processes[] , int n){
	printf("PROCESS CHART\n\n") ;
	printf("Process\t") ; 
	for ( int i = 0 ; i < n ; i++ )
		printf(" %3d ", processes[i].no) ;

	printf("\nBurst\t") ;
	for ( int i= 0 ; i< n ; i++ )
		printf(" %3d ", processes[i].burst) ; 

	printf("\nArrival\t") ;
	for ( int i= 0 ; i< n ; i++ )
		printf(" %3d ", processes[i].arrival) ; 

	printf("\nWaiting\t") ;
	for ( int i =0 ; i< n ; i++)
		printf(" %3d ", processes[i].waiting) ;

	printf("\nTAT\t") ; 
	for ( int i= 0 ; i< n ; i++ ) 
		printf(" %3d ", processes[i].turnaround) ;
	
	printf("\n\n") ;
}



void sjfs(Process processes[] , int n ){ 
    Gantt *gantt = producesGantt(processes,n,false) ; 
    printGantt(gantt) ;
    printProcess(processes,n) ; 
	printf("Average waiting time = %lf\n" ,avgWaiting(processes, n)) ; 
	printf("Average TurnAround time = %lf\n" ,avgTAT(processes, n)) ; 
	printf("Throughput  = %.3f",throughput(processes,n)) ;

}


void srtf(Process processes[] , int n ){ 
    Gantt *gantt = producesGantt(processes,n,true) ; 
    printGantt(gantt) ;
    printProcess(processes,n) ; 
	printf("Average waiting time = %lf\n" ,avgWaiting(processes, n)) ; 
	printf("Average TurnAround time = %lf\n" ,avgTAT(processes, n)) ; 
	printf("Throughput  = %.3f",throughput(processes,n)) ;

}
