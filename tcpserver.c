#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h> 
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
void func(int connfd)
{
char buff[MAX];
int n;
for(;;) 
{
bzero(buff,MAX);
read(connfd,buff,sizeof(buff));
printf("\nFrom client:%s\nTo client:",buff);
bzero(buff,MAX);
n=0;
while((buff[n++]=getchar())!='\n')
;
write(connfd,buff,sizeof(buff));
if(strncmp("exit",buff,4)==0) 
{
printf("\nServer Exit...");
break;
}
}
}
void main()
{
int sockfd,connfd,len;
struct sockaddr_in servaddr,cli;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1) 
{
printf("\nSocket creation failed...");
exit(0);
}
else
printf("\nSocket successfully created...");
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(PORT);
if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr)))!=0) 
{
printf("\nSocket bind failed...");
exit(0);
}
else
printf("\nSocket successfully binded...");
if((listen(sockfd,5))!=0) 
{
printf("\nListen failed...");
exit(0);
}
else
printf("\nServer listening...");
len=sizeof(cli);
connfd=accept(sockfd,(SA*)&cli,&len);
if(connfd<0) 
{
printf("\nServer accept failed...");
exit(0);
}
else
printf("\nServer accept the client...");
func(connfd);
close(sockfd);
}
