#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
void main()
{
FILE *fp;
int sd,newsd,ser,n,a,cli,pid,bd,port,clilen;
char name[100],fileread[100],fname[100],ch,file[100],rcv[100];
struct sockaddr_in servaddr,cliaddr;
printf("\nEnter port address:");
scanf("%d",&port);
sd=socket(AF_INET,SOCK_STREAM,0);
if(sd<0)
printf("\nCan't create...");
else
printf("\nSocket is created successfully...");
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(port);
a=sizeof(servaddr);
bd=bind(sd,(struct sockaddr *)&servaddr,a);
if(bd<0)
printf("\nCan't bind...");
else
printf("\nBinded...");
listen(sd,5);
clilen=sizeof(cliaddr);
newsd=accept(sd,(struct sockaddr*)&cliaddr,&clilen);
if(newsd<0)
printf("\nCan't accept...");
else
printf("\nAccepted...");
n=recv(newsd,rcv,100,0);
rcv[n]='\0';
fp=fopen(rcv,"r");
if(fp==NULL)
{
send(newsd,"error",5,0);
close(newsd);
}
else
{
while(fgets(fileread,sizeof(fileread),fp))
{
if(send(newsd,fileread,sizeof(fileread),0)<0)
printf("\nCan’t send file contents...");
sleep(1);
}
if(!fgets(fileread,sizeof(fileread),fp))
send(newsd,"completed",10,0);
}
}
