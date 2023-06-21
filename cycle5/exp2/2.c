#include "helper.h"

int main(){

	printf("Enter the no. of Reference string elements : " ) ; 
	scanf("%d",&refNo) ; 
	refString = (int*) malloc(sizeof(int)*refNo) ;  
	
	printf("Enter the reference string : ") ; 
	for ( int i = 0 ; i < refNo ; i++ ) 
		scanf("%d",&refString[i]) ; 
	
	printf("Enter the no. of frame : " ); 
	scanf("%d",&frameNo) ; 
	
	frameString = (int*) malloc(sizeof(int)*frameNo) ; 
	
	bool flag = true ;
	int choice ; 
	
	do{
		printf("\n1. FIFO 2. Optimal 3. LRU 4. LFU 5. Exit\n") ; 
		printf(" >> ") ; 
		scanf("%d",&choice);
		switch(choice){
			case 1: 
				printf("FIFO Page Replacement\n") ;
				fifo(); 
				break; 
			case 2: 
				printf("Optimal Page Replacement\n") ;
				optimal() ; 
				break; 
			case 3: 
				printf("LRU Page Replacement\n") ;
				lru() ; 
				break; 
			case 4:	
				printf("LFU Page Replacement\n") ;
				lfu() ;
				break; 
			case 5: flag = false ;
		}
	}while(flag) ; 	
	return 0 ;
}



// Fist In First Out Page Replacement Algo
void fifo(){
	clearString(frameString,frameNo) ; 
	int i = 0 , j = 0 ; 
	hit = miss = 0 ;
	while(i != refNo ){
		if ( ! search(frameString,frameNo,refString[i])){
			frameString[j]  =  refString[i] ;
			j =  (j+1) % frameNo ;
			miss ++ ;  
			print("miss") ;
		}else{
			hit ++ ;
			print("hit") ; 
		} 	
		i++ ;
	}
	printRatio() ;
}

// Optimal Page Replacement Algo
void optimal(){
	clearString(frameString,frameNo);
	int i = 0 , j = 0 ; 
	hit = miss = 0 ; 
	while(i != refNo){
		if( ! search(frameString,frameNo,refString[i])){
			if ( ! search(frameString,frameNo,-1)){
				int optimal = findOptimal(i) ;
				replace(optimal,refString[i]) ;
			}else{
				frameString[j] = refString[i] ;
				j = (j+1) % frameNo ; 
			}
			miss ++ ; 
			print("miss") ;
		}else{
			hit ++ ; 
			print("hit") ;
		}
		i++ ; 
	}
	printRatio() ;
}

// Least Recently Used Page Replacement Algo
void lru(){
	clearString(frameString,frameNo) ;
	int i = 0 , j = 0 ,r;
	hit = miss = 0 ;  

	while( i != refNo){
		if ( ! search(frameString,frameNo,refString[i])){
			r = recentlyUsed(i-1) ;
			if ( r > -1 ){
				replace(r,refString[i]) ;
			}else{
				frameString[j]  =  refString[i] ;
				j =  (j+1) % frameNo ;
			}	
			miss ++ ; 
			print("miss") ;
		}else{
			hit ++ ; 
			print("hit") ;
		}
		i++ ;
	}
	printRatio() ;
}
// Least Frequently Used Page Replacement Algo
void lfu(){
	int str[3][frameNo] ;
	for ( int i = 0 ; i< 3 ; i++)
		for ( int j =0  ; j < frameNo ; j++ )
			if ( i == 1 ) 
				str[i][j] = 0 ; 
			else
				str[i][j] = -1 ; 

	int i = 0 , j = 0 ;
	miss = hit = 0 ; 

	while( i != refNo ){
		int leastFreq ;
		if ( ! searching(str,refString[i])){
			if ( !searching(str,-1)){
				leastFreq = leastFrequentlyUsed(str) ;
				replaceL( str , leastFreq , refString[i] , i ) ; 
			}else{
				str[0][j]= refString[i] ; 
				str[1][j] = 0  ; 
				str[2][j] = i ; 
				j++ ;
			}
			miss++ ; 
			printing(str,"miss\t",0) ;
		}else{
			setFrequency(str,i) ; 
			hit ++ ; 
			printing(str,"hit\t",0) ;
		}
		i++ ;
	}
	printRatio();
}