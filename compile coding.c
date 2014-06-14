#include<stdio.h>
//#include<conio.h>

int phi,M,n,e,d,C,FLAG;

int check()
{
int i;
for(i=3;e%i==0 && phi%i==0;i+2)
{
FLAG = 1;
}
FLAG = 0;
}

int encrypt()
{
int i;
C = 1;
for(i=0;i< e;i++)
C=C*M%n;
C=C%n;
printf(" Encrypted keyword : %d",C);
}

int decrypt()
{
int i;
M = 1;
for(i=0;i< d;i++)
M=M*C%n;
M = M%n;
printf("\n Decrypted keyword : %d",M);
}

int main()
{
int p,q,s;

printf("Enter Two Relatively Prime Numbers\t: ");
scanf("%d%d",&p,&q);
n = p*q;
phi=(p-1)*(q-1);
printf("\nF(n) phi value\t= %d",phi);
do
{
printf("\nEnter e which is prime number and less than phi \t: ",n);
scanf("%d",&e);
check();
}while(FLAG==1);
d = 1;
do
{
s = (d*e)%phi;
d++;
}while(s!=1);
d = d-1;
printf("\nPublic Key\t: {%d,%d}",e,n);
printf("\nPrivate Key\t: {%d,%d}",d,n);
printf("\nEnter The Plain Text\t: ");
scanf("%d",&M);
encrypt();
printf("\nEnter the Cipher text\t: ");
scanf("%d",&C);
decrypt();
//getch();
}
