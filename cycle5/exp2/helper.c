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
	printf(" ] %s \n",str) ;
	
	
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
	for ( int i = 0 ; i < frameNo ; i++ ){
		if ( frameString[i] == recentlyUsed ){
			frameString[i] = key ;
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

bool searching(int (*str)[frameNo], int key){
	for ( int i =0  ; i < frameNo ; i++)
		if ( str[0][i] == key )
			return true ; 
	
	return false ; 
}

void replaceL(int (*str)[frameNo],int lfrequent ,int key,int pos){
	for ( int i = 0 ; i < frameNo ; i++ ){
		if ( str[0][i] == lfrequent ){
			str[0][i] = key ; 
			str[1][i] = 0;
			str[2][i] = pos; 
		}
	}
}

void setFrequency(int (*str)[frameNo], int pos){
	for ( int i = 0 ; i < frameNo ; i++ )
		if ( str[0][i] == refString[pos])
			str[1][i] += 1 ; 
}

void printing(int arr[][frameNo], char str[], int row ){
	printf("[ ") ; 
	for ( int i = 0 ; i< frameNo ; i++ )
		if ( arr[row][i] == -1 )
			printf(" X ") ; 
		else 
			printf(" %d ",arr[row][i] ) ; 
	
	printf("] %s\n",str) ;

}

int leastFrequentlyUsed(int (*str)[frameNo]){
	
	int minF = str[1][0] ;
	int count = 0 , j = 0 ;  
	int arr[frameNo] ;

	clearString(arr,frameNo) ;
	arr[j++] = str[1][minF] ; 
	for ( int i = 1 ; i < frameNo ; i++ ){
		if ( str[1][minF] > str[1][i] ){
			minF = i ; 
			count = 0 ;
			clearString(arr,frameNo) ;  
			j= 0 ; 
			arr[j++] = str[1][minF] ;  
		}else if ( str[1][minF] == str[1][i] ){
			count ++ ; 
			arr[j++] = i ;
		} 
	}

	if ( count == 0 )
		return str[0][minF] ;

	int fin = arr[0] ; 


	for ( int i = 1; i < frameNo ; i++ ){
		int x = arr[i] ; 
		if ( str[2][fin] > str[2][x] && x != -1 )
			fin  = x ;
		 
	}
	return str[0][fin] ; 
}