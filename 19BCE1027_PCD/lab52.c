#include<stdio.h>
#include<omp.h>

void main()
{
	int a[10],b[10],I,sum[10];
	for(int i=0;i<10;i++){
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
	}
	
	#pragma omp parallel for schedule(dynamic,1)
	for(int i=0;i<10;i++){
	sum[i] = a[i]+b[i];
	printf("CPU:%d\tThread:%d\tValue:%d\n",sched_getcpu(),omp_get_thread_num(),sum[i]);
	}
}

