#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
int n,m,i,j;
printf("Enter number of factors.\n");
scanf("%d\n",&n);
int a[n];
for(i=0;i<n;i++)
{
a[i]=i+1;
}
printf("Enter a number.\n");
scanf("%d",&m);
int sum=0;
#pragma omp parallel for firstprivate(sum)
for(i=2;i<m;i++)
{
for(j=0;j<n;j++)
{
if(a[j]%i==0)
{
sum=sum+a[j];
}
}
printf("cpu: %d\tthread: %d\tnumber: %d\tsum: %d\n",sched_getcpu(),omp_get_thread_num(),i,sum);
sum=0;
}
}

