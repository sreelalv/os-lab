#include<stdio.h>
#include<sys/wait.h>
#include<stdbool.h>
#include<unistd.h>

void fibonacci(int n ){
	printf("Fibnocci number \n") ; 
	int i = 0 ,j = 1  , count = 0; 
	if( n == 1)
		printf("%d ", i) ; 
	else if ( n == 2 )
		printf("%d %d ",i, j ) ; 
	else{	
		int k = i + j ; 
		printf("%d %d ",i, j) ; 
		for ( int x = 3 ; x <= n ; x++ ){
			printf("%d ",k) ; 
			i = j ; 
			j = k ;
			k = i+j ; 
		}
	}
}

bool isPrime(int n){
	if ( n == 0 || n== 1 ) 
		return false ; 
	else
		for ( int i= 2 ; i<= n/2 ; i++ )
			if ( n % i == 0 )
				return false ; 
	return true ; 
}

void prime(int n){
	printf("Prime Numbers\n") ;
	int count = 0 ; 
	for ( int i = 0 ; count < n ; i++)
		if ( isPrime(i) ){
			printf("%d ",i) ; 
			count++ ;	
		}		
}
 		

void forks(int n){
	int p = fork() ; 
	if ( p == -1 ) 
		printf("Error in creating process\n") ;
	else if ( p== 0 ){
		fibonacci(n) ;
	}else if ( p > 0){
		wait(NULL) ;
		prime(n) ; 
	}
}			

int main(){
	int n ; 
	printf("Enter a number : " ) ; 
	scanf("%d", &n ) ; 
	forks(n) ; 
	printf("\n") ;	
	return 0 ; 
}
