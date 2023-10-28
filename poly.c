#include<stdio.h>
void main()
{
int i,lim;
printf("\nEnter limit:");
scanf("%d",&lim);
struct poly
{
int coeff,exp;
}x[lim];
printf("\nEnter coefficients and exponents in the array:");
for(i=0;i<lim;i++)
{
scanf("%d%d",&x[i].coeff,&x[i].exp);
}
printf("\nCorresponding polynomial equation is:");
for(i=0;i<lim;i++)
{
if(i!=(lim-1))
printf("%dx^%d+",x[i].coeff,x[i].exp);
else
printf("%dx^%d",x[i].coeff,x[i].exp);
}
}
