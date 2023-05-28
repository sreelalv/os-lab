#include <stdio.h>

int Max[10][10], need[10][10], alloc[10][10],avail[10],tot[10],work[10], finish[10], safeSequence[10];
int p, r, i, j, process, count=0;

void safesequence(){
    printf("\n Max matrix:\tAllocation matrix:\n");
    for(i = 0; i < p; i++){
        for( j = 0; j < r; j++)
            printf("%d ", Max[i][j]);
        printf("\t\t");
        for( j = 0; j < r; j++)
            printf("%d ", alloc[i][j]);
        printf("\n");
    }
    do{
        process = -1;
        for(i = 0; i < p; i++){
            if(finish[i] == 0){
                process = i ;
                for(j = 0; j < r; j++){
                    if(work[j] < need[i][j]){
                        process = -1;
                        break;
                    }
                }
            }
            if(process != -1)
                break;
        }
        if(process != -1){
            safeSequence[count] = process ;
            count++;
            for(j = 0; j < r; j++){
                work[j] += alloc[process][j];
            }
            finish[process] = 1;
        }
    }while(count != p && process != -1);
    if(count == p){
        printf("\nThe system is in a safe state\n");
        printf("Safe Sequence : ");
        for( i = 0; i < p; i++)
            printf("P%d ", safeSequence[i]);
        printf("\n");
    }else
        printf("\nThe system is in an unsafe state\n");
}

void resourceAlloc(){
    int resource[10][10];
    int granted=1;
    printf("Enter the resource allocation : \n");
    for(i = 0; i < p; i++) {
        printf("\nFor process %d : ",i );
        for(j = 0; j < r; j++)
        scanf("%d", &resource[i][j]);
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            if(resource[i][j] > need[i][j]){
                granted=0;
                break;
            }
            if(resource[i][j] > avail[j]){
                granted=0;
                break;
            }
        }
        if(granted==1){
            avail[j] -= resource[i][j];
            alloc[i][j] += resource[i][j];
            need[i][j] -= resource[i][j];
        }
    }
    if(granted==1)
        printf("Resource request granted\n");
    safesequence();
}

void main(){
    printf("Enter the no of processes : ");
    scanf("%d", &p);
    for(i = 0; i< p; i++)
        finish[i] = 0;
    printf("\nEnter the no of resources : ");
    scanf("%d", &r);
    printf("\nEnter the total resources available : ");
    for(int i = 0;i< r;i++){
        scanf("%d",&tot[i]);
    }
    printf("\n\nEnter the Max Matrix for each process : ");
    for(i = 0; i < p; i++){
        printf("\nFor process %d : ", i );
        for(j = 0; j < r; j++)
            scanf("%d", &Max[i][j]);
    }
    printf("\n\nEnter the allocation for each process : ");
    for(i = 0; i < p; i++){
        printf("\nFor process %d : ",i );
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    }
    for(int i =0;i<r;i++){
        int allo=0;
        for(int j =0;j<p;j++){
            allo+=alloc[j][i];
        }
        avail[i]=tot[i]-allo;
    }
    printf("\nAvailable Resources : ");
    for(int i = 0; i < r; i++)  {
        printf("%d",avail[i]);
        work[i]=avail[i];
        finish[i]=0;
    }
    for(i = 0; i < p; i++)
        for(j = 0; j < r; j++)
            need[i][j] = Max[i][j] - alloc[i][j];
    safesequence();
    for(int i =0;i<r;i++){
        work[i]=avail[i];
        finish[i]=0;
    }
    resourceAlloc();
}