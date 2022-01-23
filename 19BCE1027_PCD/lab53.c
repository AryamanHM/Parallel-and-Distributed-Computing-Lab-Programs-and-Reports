#include <stdio.h>
#include <omp.h>
int main (void)
{
    int i = 10;
	int j;
	omp_set_num_threads(3);
    #pragma omp parallel for firstprivate(i) schedule(static,2)
	
		
		for(j=0;j<6;j++){
        i = j+i;
		printf("thread %d: i = %d\n", omp_get_thread_num(), i);
        
		
		}
     
}

