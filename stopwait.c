#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int snd_packet(int packet_no) 
{
printf("\nSending packet:%d",packet_no);
if(rand()%2==0) 
{
printf("\nPacket %d sent successfully",packet_no);
return 1; 
} 
else 
{
printf("\nPacket %d transmission failed",packet_no);
return 0;
}
}
int rec_ack(int packet_no) 
{
if(rand()%2==0) 
{
printf("\nAcknowledgment received for packet %d", packet_no);
return 1; 
} 
else 
{
printf("\nNo acknowledgment for packet %d", packet_no);
return 0; 
}
}
void main() 
{
int num_packets,max_retries,timeout,packet_no=1,retries=0,success=0;
srand(time(0));
printf("\nEnter the number of packets to send:");
scanf("%d",&num_packets);
printf("\nEnter the maximum number of retries:");
scanf("%d",&max_retries);
printf("\nEnter the timeout period (in seconds):");
scanf("%d",&timeout);
while(packet_no<=num_packets) 
{  
retries=0;
success=0;
while(retries<max_retries&&!success)
{
if(snd_packet(packet_no)) 
{
sleep(timeout);  
if(rec_ack(packet_no)) 
{
success=1;  
break;
}
}
retries++;
printf("\nRetrying...(Attempt %d)",retries);
}
if(!success) 
printf("\nFailed to transmit packet %d after %d retries",packet_no,retries);
packet_no++;
}
printf("\nTransmission completed");
}
