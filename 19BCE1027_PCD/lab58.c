#include<stdio.h>
#include<omp.h>

void main()
{
	
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int i,k;
	int oddsum=0;
	int evensum=0;
	
	omp_set_num_threads(2);
	#pragma omp parallel for schedule(static,2)
	
		for(i=0;i<10;i++){
			if(a[i]%2==0){
				evensum+=a[i];
				
				printf("Thread:%d\t a[i]:%d \t evensum:%d\n",omp_get_thread_num(),a[i],evensum);
			}
			else{
				oddsum+=a[i];
			
			printf("Thread:%d\t a[i]:%d \t oddsum:%d\n",omp_get_thread_num(),a[i],oddsum);
			}		
		}
	
	printf("evensum: %d\n",evensum);
	printf("oddsum: %d\n",oddsum);
}

