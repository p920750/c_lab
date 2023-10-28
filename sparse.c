#include<stdio.h>
void main()
{
int m,n,lim,i,j;
printf("\nEnter no of rows and coloumns:");
scanf("%d%d",&m,&n);
int a[m][n];
printf("\nEnter nubers in sparse matrix:");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("\nEnter limit:");
scanf("%d",&lim);
struct sparse
{
int row,coloumn,val;
}sp[lim];
int k=1,count=0;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]!=0)
{
sp[k].row=i;
sp[k].coloumn=j;
sp[k].val=a[i][j];
count++;
k++;
}
}
sp[0].row=m;
sp[0].coloumn=n;
sp[0].val=count;
}
printf("\nValues in tupil matrix is:");
printf("\nRow: Coloumn: Value:\n");
for(i=0;i<k;i++)
{
printf("\n%d\t%d\t%d\n",sp[i].row,sp[i].coloumn,sp[i].val);
}
}          
