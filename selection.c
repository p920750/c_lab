#include<stdio.h>
void main()
{
int i,j,lim,min=0,c=0,temp;
c=c+2;
printf("\nEnter limit:");
scanf("%d",&lim);
c++;
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
min=i;
c++;
for(j=i+1;j<lim;j++)
{
c++;
if(a[min]>a[j])
{
c++;
min=j;
c++;
}
c++;
}
c++;
temp=a[i];
c++;
a[i]=a[min];
c++;
a[min]=temp;
c++;
}
c++;
printf("\nNumbers in acending order is:");
for(i=0;i<lim;i++)
{
c++;
printf("%d\t",a[i]);
c++;
}
c++;
printf("\nSpace complexity=%d",(24+(4*lim)));
c=c+2;
printf("\nTime complexity=%d",c);
}
