#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void  printError(){
	printf("Error in process creation\n") ; 
}

void main(){
	int f1 = fork() ; 
	if ( f1 == -1 )
		printError() ; 
	else if ( f1 == 0 ){
		sleep(2) ; 
		printf("First child : %d  ppid : %d \n",getpid() ,getppid())  ; 
	}else {
		int f2 = fork() ; 
		if ( f2 == -1 ) 
			printError() ; 
		else if ( f2 == 0 ){
			sleep(1) ;
			printf("Second child : %d  ppid : %d\n",getpid(),getppid()) ; 
		}else{
			int f3 = fork() ; 
			if ( f3 == -1 )
				printError() ; 
			else if ( f3 == 0 ) 
				printf("Third child : %d  ppid : %d \n",getpid(),getppid()) ; 
			else{
				sleep(3) ;
				printf("Parent Process : %d   ppid : %d\n",getpid(),getppid()) ; 
			}
		}
	}
}
