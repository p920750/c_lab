/**#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
void main()
{
void *process1;
key_t key;
char ar[10];
key=ftok(".","s");
printf("\nKey id is:%d",key);
int id=shmget(key,1024,0644|IPC_CREAT);
printf("\nId of shared memory is:%d",id);
if(id==-1)
printf("\nShared memory is not created");
else
printf("\nShared memory is created");
process1=shmat(id,NULL,0);
printf("\nAddress where process is attached is:%p",process1);
printf("\nEnter some data to write into the shared memory:");
read(0,ar,10);
strcpy(process1,ar);
//printf("\nData in shared memory is:");
//puts(process1);
printf("\nData in shared memory is:%s",(char *)process1);
key=shmdt(process1);
printf("\nDetach id is:%d",key);
if(key==-1)
printf("\nDetachtion unsuccessful");
else
printf("\nDetachtion successful");
key=shmctl(id,IPC_RMID,0);
printf("\nRemoval id is:%d",key);
if(key==-1)
printf("\nShared memory is no removed");
else
printf("\nShared memory is removed successfully");
}****/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#define SEGSIZE 100
int main(int argc,char *argv[ ])
{
int shmid,cntr;
key_t key;
char *segptr;
char buff[]="Hello";
key=ftok(".",'s');
if((shmid=shmget(key,SEGSIZE,IPC_CREAT|IPC_EXCL|0666))==-1)
{
if((shmid=shmget(key,SEGSIZE,0))==-1)
{
perror("shmget");
exit(1);
}
}
else
{
printf("\nCreated a new shared memory successfully");
printf("\nShm id is:%d",shmid);
}
system("ipcs –m");
if((segptr=(char*)shmat(shmid,0,0))==(char*)-1)
{
perror("shmat");
exit(1);
}
printf("\nWriting data to shared memory…");
strcpy(segptr,buff);
printf("\nReading data from shared memory…");
printf("\nData in shared memory is:%s",segptr);
printf("Detaching\n");
shmdt(segptr);
printf("\nRemoving shared memory…");
if(shmctl(shmid,IPC_RMID,0)== -1)
printf("\nRemoval failed");
else
printf("\nRemoved successfully");
}
