#include<stdio.h>
void main() 
{
int in,out,bucketsize,l,store=0;
printf("\nEnter bucket size,outgoing rate and number of inputs:");
scanf("%d %d %d",&bucketsize,&out,&l);
while(l!= 0) 
{
printf("\nEnter the incoming packet size:");
scanf("%d",&in);
printf("\nIncoming packet size: %d",in);
if(in<=(bucketsize-store)) 
{
store=store+in;
printf("\nBucket buffer size:%d out of %d", store,bucketsize);
} 
else 
{
printf("\nDropped %d packet(s)",in-(bucketsize-store));
store=bucketsize;
printf("\nBucket buffer size:%d out of %d",store,bucketsize);
}
if(store>=out) 
{
store=store-out;
} 
else 
store=0;
printf("\nAfter outgoing, %d packet(s) left in buffer (out of %d)",store,bucketsize);
l--;
}
}
