#include <mpi.h>
#include <stdio.h>
int main(int argc, char **argv)
{
int rank;
int a, b, send_data;
const int root = 0;
MPI_Init(&argc, &argv);
MPI_Comm_rank (MPI_COMM_WORLD, &rank);
int world_size;
MPI_Comm_size(MPI_COMM_WORLD, &world_size);
if (rank != root)
{
b=2;
MPI_Recv(&a, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
printf("Process [P%d]: received data %d\n", rank, a);
send_data=b;
}
else{
a=1;
send_data-a;
}
printf("Process p[%d]: sent data %d\n", rank, send_data);
MPI_Send(&send_data, 1, MPI_INT, (rank+1)%world_size,0, MPI_COMM_WORLD);
if (rank==root) {
MPI_Recv(&b, 1, MPI_INT, 1, 0, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
printf("Process [P%d]: received data %d\n", rank, b);
}
MPI_Finalize();
return 0;
}
