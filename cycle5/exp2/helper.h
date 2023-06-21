#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int refNo , frameNo ;
int *refString , *frameString ; 
int hit , miss ; 

bool search( int* , int , int );
void print(char[]) ;
void clearString() ;
void printRatio() ;
void replace(int , int ) ; 
int recentlyUsed(int);
int findOptimal(int) ;
bool searching(int (*str)[frameNo], int );
int leastFrequentlyUsed(int (*arr)[frameNo]);
void replaceL(int (*arr)[frameNo],int ,int ,int );
void setFrequency(int (*arr)[frameNo], int );



void fifo() ;
void optimal() ; 
void lru() ; 
void lfu() ;  

void printing(int str[][frameNo],char [],int) ;
#endif //HEADER_H