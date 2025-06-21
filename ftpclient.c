#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<string.h>
void main()
{
FILE *fp;
int csd,s,cport;
char name[100],rcvmsg[100],rcvg[100],fname[100];
struct sockaddr_in servaddr;
printf("\nEnter the port:");
scanf("%d",&cport);
csd=socket(AF_INET,SOCK_STREAM,0);
if(csd<0)
{
printf("\nError....");
exit(0);
}
else
printf("\nSocket is created successfully...");
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(cport);
if(connect(csd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
printf("\nError in connection...");
else
printf("\nConnected...");
printf("\nEnter the existing file name:");
scanf("%s",name);
printf("\nEnter the new file name:");
scanf("%s",fname);
fp=fopen(fname,"w");
send(csd,name,sizeof(name),0);
while(1)
{
s=recv(csd,rcvg,100,0);
rcvg[s]='\0';
if(strcmp(rcvg,"error")==0)
printf("\nFile is not available");
if(strcmp(rcvg,"completed")==0)
{
printf("\nFile is transferred...");
break;
}
else
{
fputs(rcvg,fp);
fputs(rcvg,stdout);
}
}
fclose(fp);
close(csd);
}
