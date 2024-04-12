#include<stdio.h>
void main()
{
int i,j,lim,total_wt=0,total_tat=0,temp1,temp2,temp3;
float avg_wt,avg_tat;
printf("\nEnter the number of processes:");
scanf("%d",&lim);
int p[lim],bur[lim],wt[lim],tat[lim],pri[lim];
printf("\nEnter the names of processes,their burst time and priority respectively:");
for(i=0;i<lim;i++)
scanf("%d%d%d",&p[i],&bur[i],&pri[i]);
for(i=0;i<lim;i++)
{
for(j=i+1;j<lim;j++)
{
if(pri[i]>pri[j])
{
temp1=pri[i];
temp2=bur[i];
temp3=p[i];
pri[i]=pri[j];
bur[i]=bur[j];
p[i]=p[j];
pri[j]=temp1;
bur[j]=temp2;
p[j]=temp3;
}
}
}
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
printf("\nProcesses   Waiting Time   Burst Time   Turn Around Time   Priority\n");
for(i=0;i<lim;i++)
printf("\n%d\t%d\t%d\t%d\t%d",p[i],wt[i],bur[i],tat[i],pri[i]);
printf("\nTotal waiting time=%d\nTotal turn around time=%d\nAverage waiting time=%f\nAverage turn around time=%f",total_wt,total_tat,avg_wt,avg_tat);
}
