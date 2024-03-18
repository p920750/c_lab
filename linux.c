#include<stdio.h>
#include<unistd.h>
void main()
{
int pid,lim,n;
pid=fork();
if(pid==0)
{
printf("\nChild process:");
printf("\nProcess id is:%d",getpid());
printf("\nParent id is:%d",getppid());
printf("\nEnter limit:");
scanf("%d",&lim);
printf("\nNatural numbers are:");
for(int i=1;i<=lim;i++)
printf("%d ",i);
}
else if(pid>0)
{
wait();
printf("\nParent process:");
printf("\nProcess id is:%d",getpid());
printf("\nEnter a number:");
scanf("%d",&n);
if(n%2==0)
printf("%d is an even number",n);
else
printf("%d is an odd number",n);
}
else
printf("\nFork failed!!");
}
