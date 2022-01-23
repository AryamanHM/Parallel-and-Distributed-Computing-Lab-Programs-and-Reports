#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<mpi.h>
#include<math.h>
void generate(int);
void check(int,int);
int a[500];
int main ()
{ 
	int n=5,i;
	MPI_Init(NULL, NULL);
	int id,p;
	MPI_Comm_rank(MPI_COMM_WORLD,&id);
	MPI_Comm_size(MPI_COMM_WORLD,&p);
	int m = pow(2,n);
	generate(m);
	for(i=id;i<m;i+=p){
		check(id,i);
	}
	MPI_Finalize();
}
void generate(int m)
{
	int i;
	for(i=0;i<m;i++){
		a[i] = rand() % (1 - 0 + 1) + 0;
	}
}
void check(int id,int i)
{
	if(a[i]==1){
		printf("\n%dth row satisfies circuit",i);
	}
	else
	{
		printf("\n%dth row does not satisfies circuit\n",i);
	}
}


