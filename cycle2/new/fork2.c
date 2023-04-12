#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	int p = fork() ; 
	if ( p == -1 )
		printf("Error in process creation\n ") ; 
	else if (p == 0 ) 
		printf("child\tpid = %d \t ppid = %d\n",getpid(),getppid() ) ; 
	else{ 	
	//	wait(NULL) ; 
		printf("Parent\t pid = %d \t ppid = %d\n",getpid(),getppid() ) ; 
	}
	return 0 ; 
}
