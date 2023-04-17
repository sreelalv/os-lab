#include <stdio.h>
#include<stdlib.h>
int A[10];
int k=0;
struct fcfs
{
    int pid;
    int btime;
    int wtime;
    int ttime;
}p[10];

void fcfs()
{
    int i,n;
    int totw=0;
    int totu=0;
    float tp=0;
    printf("\nFCFS SCHEDULING..\n");
    printf("enter the number of process\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p[i].pid=1;
        printf("burst time of process\n");
        scanf("%d",&p[i].btime);
        
    }
    
   
    p[0].wtime=0;
    p[0].ttime=p[0].btime;
    
    
   
    for(i=0;i<=n;i++)
    {
        p[i].wtime=p[i-1].wtime+p[i-1].btime;
        p[i].ttime=p[i].wtime+p[i].btime;
        totu+=p[i-1].ttime;
        totw+=p[i-1].wtime;
        tp+=p[i].btime;
        
        
        
    }
    
     printf("\nGANT CHART..\n");
    for(i=0;i<n;i++)
    { 
       
        printf("  p%d",i+1);
        printf("\t");
    }
    printf("\n");
    for(i=0;i<=n;i++)
    { 
        
         printf("%d\t",p[i].wtime);
    }
    
    printf("\ntotal waiting time is %d\n",totw);
    printf("avg waiting time is %d\n",(totw/n));
     printf("total turn around time is %d\n",totu);
    printf("avg turnaround time is %d\n",(totu/n));
    printf("throughput is %f\n",(n/tp));
}

struct sjfs
{
     int pid2;
    int sbtime;
    int swtime;
    int sttime;
}sp[10],tmp[10],tmp2[10];

void sjfs()
{
    int i,n,j;
    int stotw=0;
    int stotu=0;
    float stp=0;
    printf("\nSJFS SCHEDULING..\n");
    printf("enter the number of process\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        sp[i].pid2=i;
        printf("burst time of process\n");
        scanf("%d",&sp[i].sbtime);
        
    }
    sp[0].swtime=0;
    sp[0].sttime=sp[0].sbtime;
    
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(sp[i].sbtime>sp[j].sbtime)
            {	
                tmp[i]=sp[i];
                sp[i]=sp[j];
                sp[j]=tmp[i];
		    
            }}}
    for(i=0;i<=n;i++)
    {
        sp[i].swtime=sp[i-1].swtime+sp[i-1].sbtime;
        sp[i].sttime=sp[i].swtime+sp[i].sbtime;
        stotu+=sp[i-1].sttime;
        stotw+=sp[i-1].swtime;
          stp+=sp[i].sbtime;
        
    }
    
     printf("\nGANT CHART..\n");
    for(i=0;i<n;i++)
    { 
       
        printf("  p%d",sp[i].pid2);
        printf("\t");
    }
    printf("\n");
    for(i=0;i<=n;i++)
    { 
        
         printf("%d\t",sp[i].swtime);
    }
    
    printf("\ntotal waiting time is %d\n",stotw);
    printf("avg waiting time is %d\n",(stotw/n));
     printf("total turn around time is %d\n",stotu);
    printf("avg turnaround time is %d\n",(stotu/n));
     printf("throughput is %f\n",(n/stp));           
            }
        
    
void main()
{int c;
    
    while(1){
        printf("enter ur choice 1)FCFS 2)SJFS 3)exit \n");
    scanf("%d",&c);
    if(c==1)
      fcfs();
    else if(c==2)
    sjfs();
    else
    break;
}}
