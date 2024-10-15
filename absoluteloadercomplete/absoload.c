#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
FILE *objcode;
int i,length;
char line[50],ar[10];
objcode=fopen("objcode.txt","r");
fscanf(objcode,"%s",line);
printf("\nName of program is:");
for(i=4;i<8;i++)
printf("%c",line[i]);
printf("\n");
do
{
fscanf(objcode,"%s",line);
if(line[0]=='T')
{
for(i=0;i<6;i++)
ar[i]=line[i+2];
length=atoi(ar);
i=12;
while(line[i]!='\0')
{
if(line[i]!='^')
{
printf("%d:\t%c%c\n",length,line[i],line[i+1]);
length++;
i+=2;
}
else
i++;
}
}
else if(line[0]=='E')
break;
}
while(!feof(objcode));
fclose(objcode);
}
