#include "helper.h"

bool search(int *str,int fno, int key){
	for( int i = 0 ; i< fno ; i++){
		if(str[i] == key )
			return true ; 
	}
	return false ; 
}
void clearString(int str[], int n){
	for ( int i = 0 ; i< n ; i++ )
		str[i] = -1 ; 
}
void print(char str[]){
	printf("[ ") ; 
	for( int i = 0 ; i< frameNo ; i++ )
		if ( frameString[i] == -1 ) 
			printf(" X ") ; 
		else
			printf(" %d ",frameString[i]); 
	printf(" ] ") ;
	if ( !strcmp(str,"hit") ) 
		printf("Hit \n") ; 
	else 
		printf("Miss \n") ; 
	
}
void printing(int str[]){
	printf("[ ") ; 
	for( int i = 0 ; i< frameNo ; i++ )
		if ( str[i] == -1 ) 
			printf(" X ") ; 
		else
			printf(" %d ",str[i]); 
	printf(" ] ") ;
	 
	
}

void printRatio(){	
	printf("Hit = %d \n",hit) ;
	printf("Hit ratio   = %.2lf \n",(double)hit/refNo) ; 
	printf("Miss ratio = %.2lf \n",(double)miss/refNo ) ;
}

int recentlyUsed(int pos){
	int str[frameNo];
	int i = 0 ;
	clearString(str,frameNo);	
	while(pos >= 0 && i < frameNo ){
		if ( ! search(str,frameNo,refString[pos])){
			str[i++] = refString[pos--] ;
		}else
			pos--;
	}

	return str[frameNo-1] ;
	
}

void replace(int recentlyUsed,int key){
	bool flag = false ; 
	for ( int i = 0 ; i < frameNo ; i++ ){
		if ( frameString[i] == recentlyUsed ){
			frameString[i] = key ;
			flag = true ;  
		}
	}
}

int findOptimal(int pos){
	int str[frameNo],str1[frameNo];
	int i = 0 , p = pos ; 
	clearString(str,frameNo);	
	while(pos < refNo && i < frameNo ){
		if ( search(frameString,frameNo,refString[pos])){
			if ( ! search(str,frameNo,refString[pos])){
				str[i++] = refString[pos++] ; 
			}else{
				pos++;
			}
		}else
			pos++ ;
	}
	if ( search(str,frameNo,-1)){
		int k = 0; 
		clearString(str1,frameNo) ; 
		for ( int a = 0 ; a< frameNo ; a++){
			if( !search(str,frameNo,frameString[a]) )
				str1[k++] = frameString[a];
		}
		return str1[0] ;
	}
	return str[i-1] ;
}