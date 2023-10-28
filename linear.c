#include<stdio.h>
void main()
{
int n,lim,i,k=0,c=0;
c=c+2;
printf("\nEnter limit and number:");
scanf("%d%d",&lim,&n);
c=c+2;
int a[lim];
printf("\nEnter numbers:");
for(i=0;i<lim;i++)
{
c++;
scanf("%d",&a[i]);
c++;
}
c++;
for(i=0;i<lim;i++)
{
c++;
if(n==a[i])
{
c++;
k=1;
c++;
break;
}
c++;
}
c++;
if(k==1)
{
c++;
printf("\n%d is  present",n);
}
else
{
c++;
printf("\n%d is not present",n);
}
c++;
printf("\nSpace complexity=%d",20+(4*lim));
c++;
printf("\nTime complexity=%d\n",c);
}
