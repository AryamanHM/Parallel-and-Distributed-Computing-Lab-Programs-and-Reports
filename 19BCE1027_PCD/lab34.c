#include <omp.h>
#include <stdio.h>
int main ()
{ 
int n=5,n1=0,n2=1,n3,fact=1,flag=0;
#pragma omp parallel sections
{
#pragma omp section
{
printf("Fibonacci series: 0 1");
for(int i=2;i<n;i++)
{
n3=n1+n2; 
printf(" %d",n3); 
n1=n2; 
n2=n3; 
}
printf("\n");
}
#pragma omp section
{
for(int i=1;i<=n;i++)
{
fact=fact*i;
}
printf("The factorial of %d is: %d\n",n,fact);
}
#pragma omp section
{
for (int i=2; i<=n/2;i++) 
{
if (n%i==0) 
{
flag = 1;
break;
}
}
if (n==1) 
{
printf("1 is neither prime nor composite\n");
} 
else 
{
if (flag == 0)
printf("%d is a prime number\n",n);
else
printf("%d is not a prime number\n",n);
}
}
}
}
