#include<stdio.h>
void main()
{
int i,j,lim,c=0,temp;
c=c++;
printf("\nEnter limit :");
scanf("%d",&lim);
c=c++;
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
printf("\nSpace complexity=%d",(20+(4*lim)));
c=c+2;
printf("\nTime complexity=%d",c);
}
