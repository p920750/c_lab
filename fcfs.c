#include<stdio.h>
void main()
{
int i,lim,total_wt=0,total_tat=0;
float avg_wt,avg_tat;
printf("\nEnter the number of processes:");
scanf("%d",&lim);
int p[lim],bur[lim],wt[lim],tat[lim];
printf("\nEnter the names of processes and their burst time respectively:");
for(i=0;i<lim;i++)
scanf("%d%d",&p[i],&bur[i]);
wt[0]=0;
for(i=1;i<lim;i++)
{
wt[i]=wt[i-1]+bur[i-1];
total_wt=total_wt+wt[i];
}
tat[0]=bur[0];
total_tat=total_tat+tat[0];
for(i=1;i<lim;i++)
{
tat[i]=tat[i-1]+bur[i];
total_tat=total_tat+tat[i];
}
avg_wt=(double)total_wt/lim;
avg_tat=(double)total_tat/lim;
printf("\nProcesses   Waiting Time   Burst Time   Turn Around Time\n");
for(i=0;i<lim;i++)
printf("\n%d\t%d\t%d\t%d",p[i],wt[i],bur[i],tat[i]);
printf("\nTotal waiting time=%d\nTotal turn around time=%d\nAverage waiting time=%f\nAverage turn around time=%f",total_wt,total_tat,avg_wt,avg_tat);
}
