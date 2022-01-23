#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
int rank, sum,overall_sum=0,i;
int avg;
int a[]={1,2,3},b[]={1,2,3,4},c[]={1,2,3,4,5},d[]={1,2,3,4,5,6};
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank) ;
int world_size;
MPI_Comm_size(MPI_COMM_WORLD, &world_size);
int* sub_avgs=NULL;
if(rank==0)
{
sum=0;
sub_avgs = malloc(sizeof(int) * world_size);
for(i=0;i<3;i++)
{
sum=sum+a[i];
}
avg=sum/3;
MPI_Gather(&avg,1 , MPI_INT, sub_avgs, 1, MPI_INT, 0,MPI_COMM_WORLD) ;
for(i=0;i<world_size;i++)
{
printf("Average from Process P[%d]:%d\n",i, sub_avgs[i]);
overall_sum=overall_sum+sub_avgs[i];
}
printf("\nProcess P[%d]: Overall Average=%d\n", rank, (overall_sum/world_size));
}
else
{
sum=0;
if (rank==1)
{
for(i=0;i<4;i++)
{
sum=sum+b[i];
}
avg=sum/4;
MPI_Gather(&avg,1,MPI_INT,sub_avgs,1,MPI_INT,0,MPI_COMM_WORLD);
}
if (rank==2)
{
for(i=0;i<5;i++)
{
sum=sum+c[i];
}
avg-sum/5;
MPI_Gather(&avg,1 ,MPI_INT, sub_avgs, 1, MPI_INT, 0,MPI_COMM_WORLD) ;
}
if (rank==3)
{
for(i=0;i<6;i++)
{
sum=sum+c[i];
}
avg=sum/6;
MPI_Gather(&avg,1 , MPI_INT, sub_avgs, 1, MPI_INT, 0,MPI_COMM_WORLD) ;
}
}
MPI_Finalize();
}

