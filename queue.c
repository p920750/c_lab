#include<stdio.h>
void main()
{
int i,lim,ch,item,rear=-1,front=0;
printf("\nEnter size of queue:");
scanf("%d",&lim);
int a[lim];
int k=1;
while(k!=0)
{
printf("\nEnter your choice:\n1.Enqueue\n2.Dequeue\n3.Peak\n4.Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
if(rear==(lim-1))
printf("\nOverflow:");
else
{
rear=rear+1;
printf("\nEnter a number:");
scanf("%d",&item);
a[rear]=item;
}
break;    
}
case 2:
{
if(rear<front)
printf("\nUnderflow:");
else
{
item=a[front];
front=front+1;
}
break;
}
case 3:
{
if(rear<front)
printf("\nUnderflow:");
else
printf("\nTop most number=%d",a[front]);
break;
}
case 4:
{
if(rear<front)
printf("\nUnderflow:");
else
{
printf("\nNumbers in queue are:");
for(i=front;i<=rear;i++)
printf("%d\t",a[i]);
}
break;
}
default:
{
printf("\nWrong choice!!");
}
}
printf("\nDo you want to continue:");
scanf("%d",&k);
}
}
