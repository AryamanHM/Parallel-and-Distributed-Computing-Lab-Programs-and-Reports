#include<stdio.h>
#include<omp.h>

int main(void){
	int a[]={1,2,3,4,5,6,7,8,9,10};  
	int n;
	printf("Enter value of n: ");
	scanf("%d",&n);
	int b[n];
	for(int i = 0; i < n; i++){
		b[i] = 0;
	}
	int j,k;
	int c = 2;
	omp_set_num_threads(6);
	#pragma omp parallel for schedule(static,2)
	for(k = 0; k < n; k++){
		
		for(j = 0; j < 10; j++)
		{
			if(a[j] % c == 0){
				b[k] += a[j];
			}
		}
		printf("Sum of Factors of %d -> b[%d] = %d\n",c,k,b[k]);
		
		c++;
		
	}
	return 0;
}


