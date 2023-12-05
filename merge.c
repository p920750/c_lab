#include<stdio.h>
void main()
{
int i,lim,first,last;
printf("\nEnter size of array:");
scanf("%d",&lim);
int a[lim];
first=0;
last=lim-1;
printf("\nEnter numbers:");
for(i=0;i<lim;i++)
scanf("%d",&a[i]);
mergesort(a,first,last);
}
mergesort(int a,int first,int last)
{
int mid;
if(first<last)
{
mid=(first+last)/2;
mergesort(a,first,mid);
mergesort(a,mid+1,last);
merge(a,first,mid,last);
}
}
merge(int a[],int first,int mid,int last)
{
int i=0,j=0,k=0;
int ars[k];
i=first;
j=mid+1;
k=first;
while(i<=mid&&j<=last)
{
if(a[i]==a[j])
{
ars[k]=a[i];
ars[k+1]=a[i];
i++;
j++;
k=k+2;
}
if(a[i]<a[j])
{
ars[k]=a[i];
i++;
j++;
}
if(a[j]<a[i])
{
ars[k]=a[j];
j++;
k++;
}
}
if(i>mid)
{
while(j<=last)
{
ars[k]=a[j];
j++;
k++;
}
}
if(j>last)
{
while(i<=mid)
{
ars[k]=a[i];
i++;
k++;
}
}
printf("\nSorted array is:");
for(i=0;i<=k;i++)
printf("%d ",ars[i]);
}

