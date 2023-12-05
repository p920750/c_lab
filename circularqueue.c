#include <stdio.h>
void main()
{
int k=1;
int i,lim,ch,rear=-1,front=-1,item;
printf("\nEnter size of queue:");
scanf("%d",&lim);
int a[lim];
while(k!=0)
{
printf("\nEnter your choice:\n1.Enqueue\n2.Dequeue\n3.Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
if(rear==-1&&front==-1)
{
front=0;
rear=0;
printf("\nEnter number:");
scanf("%d",&item);
a[rear]=item;
}
else if(front==((rear+1)%lim))
printf("\nOverflow:");
else
{
rear=(rear+1)%lim;
printf("\nEnter number:");
scanf("%d",&item);
a[rear]=item;
}
break;
}
case 2:
{
if(rear==-1&&front==-1)
printf("\nUnderflow:");
else if(front==rear)
{
item=a[front];
rear=-1;
front=-1;
}
else
{
item=a[front];
front=(front+1)%lim;
}
break;
}
case 3:
{
if(rear==-1&&front==-1)
printf("\nUnderflow:");
else
{
printf("\nNumbers in queue are:");
for(i=front;i<=rear;i++)
printf("%d\t",a[i]);
printf("\nPosition of front:%d",front);
printf("\nPosition of rear:%d",rear);
}
break;
}
default :
{
printf("\nWrong choice!!");
}
}
printf("\nDo you want to continue:");
scanf("%d",&k);
}
}
