#include<stdio.h>
void main()
{
int i,j,mlim,plim;
printf("\nEnter number of processes and memory blocks:");
scanf("%d%d",&plim,&mlim);
struct pro
{
int pnam,psize,pflg;
}p[plim];
struct mem
{
int mnam,msize,mflg;
}m[mlim];
printf("\nEnter name and size of each processes:");
for(i=0;i<plim;i++)
{
scanf("%d%d",&p[i].pnam,&p[i].psize);
p[i].pflg=0;
}
printf("\nEnter name and size of each memory block:");
for(j=0;j<mlim;j++)
{
scanf("%d%d",&m[j].mnam,&m[j].msize);
m[j].mflg=0;
}
for(i=0;i<plim;i++)
{
for(j=0;j<mlim;j++)
{
if(p[i].psize<=m[j].msize)
{
if(p[i].pflg!=1&&m[j].mflg!=1)
{
m[j].mflg=1;
p[i].pflg=1;
printf("\nProcess %d is allocated to the memory block %d with size %d",p[i].pnam,m[j].mnam,m[j].msize);
}
}
}
}
for(i=0;i<plim;i++)
if(p[i].pflg==0)
printf("\nProcess %d has no space in the memory block",p[i].pnam);
}
