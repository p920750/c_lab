#include <stdio.h>
void main()
{
int i,lim;
printf("Enter size of array:");
scanf("%d",&lim);
int a[lim];
printf("\nEnter numbers:");
for(i=0;i<lim;i++)
scanf("%d",&a[i]);
quicksort(a,0,lim-1);
printf("\nSorted array is:");
for(i=0;i<lim;i++)
printf("%d\t",a[i]);
}
void quicksort(int a[],int start,int end)
{
int i,j,temp,pivot;
if(start<end)
{
i=start;
pivot=start;
j=end;
while(i<j)
{
while(a[i]<=(a[pivot]&&i<end))
{
i++;
}
while(a[j]>a[pivot])
{
j--;
}
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
temp=a[pivot];
a[pivot]=a[j];
a[j]=temp;
quicksort(a,start,j-1);
quicksort(a,j+1,end);
}
}
