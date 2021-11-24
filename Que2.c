#include "mpi.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
  int rank, size;    
    
    MPI_Status status;
    MPI_Request request = MPI_REQUEST_NULL;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &size); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	
    if (rank == 0) 
    {
	    float *buffer =new float[5];
      printf("Number of processes : %d \n",size);
        //float *buffer =new float[5];
        buffer[0]=1;
        buffer[1]=2;
        buffer[2]=3;
        buffer[3]=4;
        buffer[4]=5;
        
        MPI_Isend(buffer, 5, MPI_FLOAT, 1, 12, MPI_COMM_WORLD, &request); 
    }
	float *recb =new float[5];
    if (rank == 1) 
    {
    	
    	
        MPI_Irecv(recb, 5, MPI_FLOAT, 0, 12, MPI_COMM_WORLD, &request); 
    }

    MPI_Wait(&request, &status); 

    
    if (rank == 1) {
                for(int i=0;i<5;i++)
        {
        	printf("%f ",recb[i]);
        }
        printf("\n");
    }

    MPI_Finalize();

  return 0;
}
