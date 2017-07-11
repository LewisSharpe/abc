// HEAD FILE DECS
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  // Initialize MPI environment
  MPI_Init(NULL, NULL);
  // Discover world rank and size
// rank
  int rank_of_world;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank_of_world);
// size  
  int size_of_world;
  MPI_Comm_size(MPI_COMM_WORLD, &size_of_world);

  int coin;
  // Receive from lower process and send to the higher process. 
  // Takes care of the special case of deadlock when we are the first process.
  if (rank_of_world != 0) { // if we are not process 0
    MPI_Recv(&coin, 1, MPI_INT, rank_of_world - 1, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
    printf("Process %d received coin %d from process %d\n", rank_of_world, coin,
           rank_of_world - 1);
  } else {
    // Set the token's value if you are process 0
    coin = -1;
printf("i am process 0");
  }
  MPI_Send(&coin, 1, MPI_INT, (rank_of_world + 1) % size_of_world, 0,
           MPI_COMM_WORLD);
  // Now process 0 can receive from the last process. This makes sure that at
  // least one MPI_Send is initialized before all MPI_Recvs (again, to prevent
  // deadlock)
  if (rank_of_world == 0) {
    MPI_Recv(&coin, 1, MPI_INT, size_of_world - 1, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
    printf("Process %d received coin %d from process %d\n", rank_of_world, coin,
           size_of_world - 1);
  }
  MPI_Finalize();
}

