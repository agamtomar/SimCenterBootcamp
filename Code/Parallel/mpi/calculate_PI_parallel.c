#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define DATA_SIZE 1000000

static int long numSteps = 100000;


float Area(float current_x, float step_size){
	float y, area;
	y = 4.0/(1+current_x * current_x);
	area = y * step_size;
	return area;
}


int main(int argc, char **argv){
	int numP, procID;
	
	// the usual mpi initialization
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numP);
	MPI_Comm_rank(MPI_COMM_WORLD, &procID);
	
	int *globalData=NULL;
	int localData[LUMP];
	
	// process 0 is only 1 that needs global data
	if (procID == 0) {
		globalData = malloc(LUMP * numP * sizeof(int) );
		MPI_Send(&globalData, LUMP, MPI_INT, &localData, LUMP, MPI_INT, 0, MPI_COMM_WORLD);
		
    for (int i=0; i<LUMP*numP; i++)
		globalData[i] = i;
    }
	
	MPI_Scatter(globalData, LUMP, MPI_INT, &localData, LUMP, MPI_INT, 0, MPI_COMM_WORLD);
	
	double pi = 0;
	double time = 0;
	float area, x = 0, step_size = 1.0/numSteps, sum = 0;
	for (int i=0; i<numSteps; i++){
		area = Area(x, step_size);
		sum = sum + area;
		x = x + step_size;
	}
	pi = sum;
	printf("PI=%f, duration: %f ms\n", pi, time);
	return 0;
}


