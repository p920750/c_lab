#include<stdio.h>
void main()
{
int i,lim,tq,k=0,total_wt=0,total_tat=0,total=0;
float avg_wt,avg_tat;
printf("\nEnter the number of processes and time quantum:");
scanf("%d%d",&lim,&tq);
int p[lim],bur[lim],wt[lim],tat[lim],rt[lim];
printf("\nEnter the names of processes and their burst time respectively:");
for(i=0;i<lim;i++)
scanf("%d%d",&p[i],&bur[i]);
for(i=0;i<lim;i++)
rt[i]=bur[i];
while(k!=lim)
{
for(i=0;i<lim;i++)
{
if(rt[i]>tq)
{
total=total+tq;
rt[i]=rt[i]-tq;
}
else if(rt[i]==0)
continue;
else
{
total=total+rt[i];
rt[i]=0;
tat[i]=total;
total_tat=total_tat+tat[i];
wt[i]=total-bur[i];
total_wt=total_wt+wt[i];
k++;
}
}
}
avg_wt=(float)total_wt/lim;
avg_tat=(float)total_tat/lim;
printf("\nProcesses   Waiting Time   Burst Time   Turn Around Time\n");
for(i=0;i<lim;i++)
printf("\n%d\t%d\t%d\t%d",p[i],wt[i],bur[i],tat[i]);
printf("\nTotal waiting time=%d\nTotal turn around time=%d\nAverage waiting time=%f\nAverage turn around time=%f",total_wt,total_tat,avg_wt,avg_tat);
}
