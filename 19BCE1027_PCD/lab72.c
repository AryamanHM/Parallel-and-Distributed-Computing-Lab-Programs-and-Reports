#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<mpi.h>
#include<math.h>
void check(int,int);
int main ()
{ 
	int n=10,i;
	MPI_Init(NULL, NULL);
	int id,p;
	MPI_Comm_rank(MPI_COMM_WORLD,&id);
	MPI_Comm_size(MPI_COMM_WORLD,&p);
	for(i=id;i<n;i+=p){
		check(id,i);
	}
	MPI_Finalize();
}
void check(int id,int i)
{
	int a=1,b=2,c=3;
	float val = (pow(a,i) + pow(b,i)) / pow(c,i);
	printf("for a=%d,b=%d,c=%d,i=%d the value is: %f\n",a,b,c,i,val);
}

