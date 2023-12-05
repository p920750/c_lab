#include <stdio.h>
void main()
{
int i,lim;
printf("Enter size of array:");
scanf("%d",&lim);
int a[lim];
printf("Enter numbers:");
for (i=0;i<lim;i++)
scanf("%d",&a[i]);
printf("\nArray before sorting:");
for(i=0;i<lim;i++)
printf("%d ",a[i]);
mergesort(a,0,lim-1);
printf("\nSorted array using merge sort is:");
for (i=0;i<lim;i++)
printf("%d ",a[i]);
}
void mergesort(int a[],int lb,int rb)
{
if(lb<rb)
{
int mid=lb+(rb-lb)/ 2;
mergesort(a,lb,mid);
mergesort(a,mid+1,rb);
merge(a,lb,mid,rb);
}
}  
void merge(int a[],int lb,int mid,int rb)
{
int i,j,k;
int n1= mid-lb+1;
int n2=rb-mid;
int l[n1],r[n2];
for(i=0;i<n1;i++)
l[i]=a[lb+i];
for(j=0;j<n2;j++)
r[j]=a[mid+1+j];
i=0;
j=0;
k=lb;
while (i<n1&&j<n2)
{
if(l[i]<=r[j])
{
a[k]=l[i];
i++;
}
else
{
a[k]=r[j];
j++;
}
k++;
}
while(i<n1)
{
a[k]=l[i];
i++;
k++;
}
while(j<n2)
{
a[k]=r[j];
j++;
k++;
}
}
