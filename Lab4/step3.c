/*
Eva Stenberg
COEN177L - Thursday 2:15PM
Lab4 - Developing multi-threaded applications 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int N = 15;
int M = 15;
double** matrixA;
double** matrixB;

void * copy(void * arg) { //function to copy matrixA to matrixB
    for (int i = 0; i < N; i++) {
	    for (int j = 0; j < M; j++) {
		    matrixB[i][j] = matrixA[i][j];
        }
    }
    return NULL;
}

void * multiply(void * arg) { //Once copied, multiple matrix A by 2
    for (int i = 0; i < N; i++) {
	    for (int j = 0; j < M; j++) {
		    matrixA[i][j] = matrixA[i][j]*2;
        }
    }
    return NULL;
}
void printMatrix(int r, int c, double matrix[r][c])
	{
		int i, j;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
				printf("%lf ",matrix[i][j]);
			printf("\n");
		}
	}

int main() {
    double x = 0;

    
    matrixA = (double**) malloc(N*sizeof(double*));
    for (int i=0; i<M; i++){
        matrixA[i] = (double*) malloc(M*sizeof(double));
    }
    matrixB = (double**) malloc(N*sizeof(double*));
    for (int i=0; i<M; i++){
        matrixB[i] = (double*) malloc(M*sizeof(double));
    }

    
	for (int i = 0; i < N; i++) {
	    for (int j = 0; j < M; j++) {
		    matrixA[i][j] = x++;
        }
    }
    for (int i = 0; i < N; i++) {
	    for (int j = 0; j < M; j++) {
		    matrixB[i][j] = 0;
        }
    }

	printf("Matrix A: \n");
	printMatrix(N, M, matrixA);

    pthread_t t1;
    pthread_t t2;
    pthread_create(&t1, NULL, &copy, NULL);
    pthread_create(&t2, NULL, &multiply, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

	printf("Matrix A: \n");
	printMatrix(N, M, matrixA);


    return 0;
}
