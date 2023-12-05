#include<stdio.h>
void main()
{
int i,j,temp,lim;
printf("\nEnter size of array:");
scanf("%d",&lim);
int a[10];
printf("\nEnter numbers:");
for(i=0;i<lim;i++)
scanf("%d",&a[i]);
printf("\nArray before sorting:");
for(i=0;i<lim;i++)
printf("%d ",a[i]);
for(i=1;i<lim;i++)
{
j=i;
while(a[j]<a[j-1])
{
temp=a[j];
a[j]=a[j-1];
a[j-1]=temp;
j--;
}
}
printf("\nSorted array using insertion sort is:");
for(i=0;i<lim;i++)
printf("%d ",a[i]);
}
