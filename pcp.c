#include<stdio.h>
#include<stdlib.h>
int mutex=1,empty=3,full=0;


void producer()
{
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
mutex=signal(mutex);
}


void consumer()
{
mutex=wait(mutex);
empty=signal(empty);
full=wait(full);
mutex=signal(mutex);
}


int signal(int s)
{
s++;
return s;
}


int wait(int s)
{
s--;
return s;
}


void main()
{
int k=1,ch;
while(k!=0)
{
printf("\nEnter your choice:\n1.Producer section\n2.Consumer section\n3.Exist\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
if(mutex==1&&empty!=0)
producer();
else
printf("\nBuffer is full");
}
break;
case 2:
{
if(mutex==1&&full!=0)
consumer();
else
printf("\nBuffer is empty");
}
break;
case 3:exit(0);
default:printf("\nWrong choice!!");
}
printf("\nDo you want to continue:");
scanf("%d",&k);
}
}

