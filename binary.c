#include<stdio.h>
void main()
{
int i,j,lim,n,k=0,c=0,temp,m;
c=c+2;
printf("\nEnter limit and number:");
scanf("%d%d",&lim,&n);
c=c+2;
int lb=0,ub=lim-1;
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
for(j=i;j<lim;j++)
{
c++;
if(a[i]>a[j])
{
c++;
temp=a[i];
c++;
a[i]=a[j];
c++;
a[j]=temp;
c++;
}
c++;
}
c++;
}
c++;
printf("\nSorted array in acending order is:");
for(i=0;i<lim;i++)
{
c++;
printf("%d\t",a[i]);
c++;
}
c++;
while(lb<=ub)
{
c++;
m=(lb+ub)/2;
c++;
if(n<a[m])
{
c++;
ub=m-1;
c++;
}
c++;
if(n>a[m])
{
c++;
lb=m+1;
c++;
}
c++;
if(n==a[m])
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
printf("\n%d is  present",n);
c++;
}
else
{
printf("\n%d is not  present",n);
c++;
}
printf("\nSpace complexity=%d",(40+(4*lim)));
c=c+2;
printf("\nTime complexity=%d",c);
}
