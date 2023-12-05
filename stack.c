#include<stdio.h>
void main()
{
int k=1;
int i,lim,ch,top=-1,item;
printf("\nEnter size of the stack:");
scanf("%d",&lim);
int a[lim];
while(k!=0)
{
printf("\nEnter your choice:\n1.Push\n2.Pop\n3.Peek\n4.Display\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
if(top==(lim-1))
printf("\nOverflow:");
else
{
top=top+1;
printf("\nEnter number:");
scanf("%d",&item);
a[top]=item;
}
break;
}
case 2:
{
if(top==-1)
printf("\nUnderflow");
else
{
item=a[top];
top=top-1;
}
break;
}
case 3:
{
if(top==-1)
printf("\nUnderflow");
else
printf("\nValue at top=%d",a[top]);
break;
}
case 4:
{
if(top==-1)
printf("\nUnderflow");
else
{
printf("\nNumbers in the stack are:");
for(i=0;i<=top;i++)
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
