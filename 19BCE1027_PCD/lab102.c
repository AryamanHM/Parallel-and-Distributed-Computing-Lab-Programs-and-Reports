#include <mpi.h> 
#include <stdio.h> 
int main(int argc, char **argv) 
{
int rank,world_rank,rank1; 
MPI_Init(&argc, &argv); 
MPI_Comm_rank(MPI_COMM_WORLD, &world_rank); 
int world_size; 
MPI_Comm_size(MPI_COMM_WORLD, &world_size); 
if (world_rank != 0)
{
MPI_Recv(&rank1, 1, MPI_INT, world_rank - 1, 0,MPI_COMM_WORLD, MPI_STATUS_IGNORE);
rank=world_rank; 
printf("Process P%d received rank %d from process P%d\n", world_rank,rank1, world_rank - 1);
printf("Sum of ranks=%d\n",(world_rank+rank1)); 
}
rank=world_rank; 
MPI_Send(&rank, 1, MPI_INT, (world_rank + 1) % world_size,0, MPI_COMM_WORLD); 
if (world_rank == 0) 
rank=world_rank; 
MPI_Recv(&rank1, 1, MPI_INT, world_size - 1, 0,MPI_COMM_WORLD, MPI_STATUS_IGNORE); 
printf("Process P%d received rank %d from process P%d\n", world_rank,rank1, world_size - 1); 
printf("Sum of ranks=%d\n",(world_rank+rank1)); 
MPI_Finalize(); 
}
