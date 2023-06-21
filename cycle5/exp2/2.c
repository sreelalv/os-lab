#include "helper.h"

void main(){

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
			case 1: fifo(); 
				break; 
			case 2: optimal() ; 
				break; 
			case 3: lru() ; 
				break; 
			case 4:	lfu() ;
				break; 
			case 5: flag = false ;
		}
	}while(flag) ; 	
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

void lfu(){

}