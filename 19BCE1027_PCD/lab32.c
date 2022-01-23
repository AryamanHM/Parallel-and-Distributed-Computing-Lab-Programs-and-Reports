#include <omp.h>
#include <stdio.h>
int main ()
{ 
int a[]={1,2,3,4,5};
int b=0;
#pragma omp parallel for firstprivate(b)
#pragma omp reduction(+:b)
for(int i=0;i<5;i++)
{
b=(a[i]*a[i])+b;
printf("%d\n",b);
} 
printf("The sum of the squares in the array is: %d\n",b);
}
