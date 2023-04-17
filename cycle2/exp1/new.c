#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

void printProcess(char process, int pid,int ppid){
	printf("\nPROCESS : %c \n",process) ;
	printf("Process ID: %d\n",pid);
	printf("Parent Process ID: %d\n",ppid);

}		
void printError(){
	printf("Error in process creation\n") ;
}
int main(){

	int a = fork() ; //PROCESS A
	wait(NULL) ;
	if ( a == 0 ){
		printProcess('A',getpid(),getppid());
		
		int b = fork() ;//PROCESS B
		wait(NULL) ;
		if( b == 0){
			printProcess('B',getpid(),getppid());
			
			int d = fork() ; //PROCESS D
			wait(NULL) ;
			if ( d == 0 ){
				printProcess('D',getpid(),getppid());
				
				int h = fork() ; //PROCESS H
				wait(NULL) ;
				if ( h == 0 ){
					printProcess('H',getpid(),getppid());
					
					int i = fork() ; //PROCESS I
					wait(NULL) ;
					if ( i == 0 ){
						printProcess('I',getpid(),getppid());
					}else if ( i > 0 ){
						exit(0) ;
					}else
						printError() ; //END PROCESS I			
					
				}else if ( h > 0 ){
					int j = fork() ;  //PROCESS J 
					if( j== 0){
						printProcess('J' , getpid() , getppid()) ; 
					}else if ( j > 0) {
						exit(0) ;
					}else 
						printError() ; 
				}else
					printError() ; //END PROCESS H
				
			}else if ( d > 0 ){
				int e = fork() ; //PROCESS E
				wait(NULL) ;
				if ( e == 0 ){
					printProcess('E',getpid(),getppid());
				}else if ( e > 0 ){
					int f = fork() ; //PROCESS F
					wait(NULL) ;
					if ( f == 0 ){
						printProcess('F',getpid(),getppid()); 
					}else if ( f > 0 ){
						exit(0) ;
					}else
						printError() ; //END PROCESS F
				}else
					printError() ; //END PROCESS E
					
				
			}else
				printError() ; //END PROCESS D
				
		}else if (b > 0 ){
			int c = fork() ; //PROCESS C 
			wait(NULL) ;
			if ( c == 0 ){
				printProcess('C',getpid(),getppid());
				
				int g = fork() ; //PROCESS G
				wait(NULL) ;
				if ( g == 0 ){
					printProcess('G',getpid(),getppid());
				}else if ( g > 0 ){
					int k = fork()  ; //PROCESS K 
					wait(NULL )  ; 
					if ( k == 0 ) {
						printProcess('K',getpid() , getppid() ) ; 
					}else if ( g > 0 )
						exit(0 ) ; 
					else 
						printError() ; 
				
				}else
					printError() ; //END PROCESS G
			}else if ( c > 0 ){
				exit(0) ;
			}else
				printError() ; //END PROCESS C
		}else
			printError() ; //END PROCESS B
			
		
	}else if ( a > 0 ){
		exit(0) ;
	}else
		printError() ; //END PROCESS A 	
	exit(0) ;		
	return 0 ; 	
}










