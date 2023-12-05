#include<stdio.h>
void main()
{
int i,n,pos,ch=1;
printf("\nEner number of nodes:");
scanf("%d",&n);
int a[n];
printf("\nEnter numbers in the tree:");
for(i=1;i<=n;i++)
scanf("%d",&a[i]);
printf("\nNumbers in the tree are:");
for(i=1;i<=n;i++)
printf("%d ",a[i]);
while(ch!=0)
{
printf("\nEnter the position of a node:");
scanf("%d",&pos);
if((pos/2)!=0)
printf("\nParent node of %d is:%d",a[pos],a[pos/2]);
else
printf("\nNo parent node:");
if((2*pos)>n)
printf("\nNo left child:");
else
printf("\nLeft child of %d is:%d",a[pos],a[2*pos]);
if(((2*pos)+1)>n)
printf("\nNo right child:");
else
printf("\nRight child of %d is:%d",a[pos],a[2*pos+1]);
printf("\nDo you want to continue:");
scanf("%d",&ch);
}
}
