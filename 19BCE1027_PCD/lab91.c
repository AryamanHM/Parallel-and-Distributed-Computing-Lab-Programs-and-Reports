#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
float *create_rand_nums(int  n)
{
    float *rnd=(float *) malloc(sizeof(float)*n);
    int i;
    for(i=0;i<n;i++)
    {
		rnd[i]=rand();
    }
	return rnd;
}

int main(int argc, char *argv[])
{
    MPI_Init(&argc,&argv);
    int id;
	int p,i;
	int num_elements_per_proc=1;
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    float *rand_nums = NULL;
    if(id==0) 
	{
	    rand_nums = create_rand_nums(p);
	}
	float *sub_rand_nums = (float *)malloc(sizeof(float) * p);
    MPI_Scatter(rand_nums, num_elements_per_proc, MPI_FLOAT, sub_rand_nums, 1, MPI_FLOAT, 0, MPI_COMM_WORLD);
	if(id>0)
	{
		printf("\nData recieved: ");
    	for( i=0;i<p;i++)
    	{
    		printf("%.2f ",sub_rand_nums[i]);	
		}
		printf("\n");
	}
    MPI_Finalize();
    return 0;
}
