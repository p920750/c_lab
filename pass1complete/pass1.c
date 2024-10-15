#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
FILE *input,*optab,*symtab,*intermediate,*proglength;
int locctr,start,programlength,flag;
char opcode[20],operand[20],label[20],mneumonic[20],code[20];
input=fopen("input.txt","r");
optab=fopen("optab.txt","r");
symtab=fopen("symtab.txt","w");
intermediate=fopen("intermediate.txt","w");
proglength=fopen("proglength.txt","w");
fscanf(input,"%s\t\t%s\t\t%s",label,opcode,operand);
if(strcmp(opcode,"START")==0)
{
start=atoi(operand);
locctr=start;
fprintf(intermediate,"\t\t\t%s\t\t%s\t\t%s\n",label,opcode,operand);
}
else
locctr=0;
fscanf(input,"%s\t\t%s\t\t%s",label,opcode,operand); 
while(strcmp(opcode,"END")!=0)
{
fprintf(intermediate,"%d\t\t%s\t\t%s\t\t%s\n",locctr,label,opcode,operand);
flag=0;
if(strcmp(label,"**")!=0)
fprintf(symtab,"%s\t\t%d\n",label,locctr);
if(strcmp(opcode,"WORD")==0)
locctr+=3;
else if(strcmp(opcode,"RESW")==0)
locctr+=(3*atoi(operand));
else if(strcmp(opcode,"RESB")==0)
locctr+=atoi(operand);
else if(strcmp(opcode,"BYTE")==0)
locctr+=(strlen(operand)-3);
else
{
locctr+=3;
flag=1;
}
fscanf(input,"%s\t\t%s\t\t%s",label,opcode,operand); 
}
fprintf(intermediate,"%d\t\t%s\t\t%s\t\t%s\n",locctr,label,opcode,operand);
programlength=locctr-start;
fprintf(proglength,"%d",programlength);
fclose(input);
fclose(optab);
fclose(symtab);
fclose(intermediate);
fclose(proglength);
}
