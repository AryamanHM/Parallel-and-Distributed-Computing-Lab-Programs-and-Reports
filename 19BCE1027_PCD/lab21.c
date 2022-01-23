#include<stdio.h>
#include<omp.h>
int main(void)
{
int i=10;
int j=0;
#pragma omp parallel for 
for(j=0;j<6;j++)
{
i=j+i;
printf("thread %d:i=%d\n",omp_get_thread_num(),i);
}
printf("i= %d\n",i);
return 0;
}

