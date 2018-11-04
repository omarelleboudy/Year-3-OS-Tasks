#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 

 
#define N 8
#define M 4 

pthread_t threads[N]; 
int A[M][M] = { {1,4,3,5}, {1,12,3,32}, {4,2,4,4}, {1,2,3,4} },
    B[M][M] = { {14,53,42,1}, {4,3,334,1}, {14,23,23,41}, {34,45,58,61} }, 
    sum[M][M]; 

void* Sum(void* arg);



int main() 
{ 
    int i, j, it = 0; 

    for(i = 0; i < N; i++)
      pthread_create(&threads[i], NULL, &Sum, (void*)it++);
      
  
    for(i = 0; i < N ; i++) 
      pthread_join(threads[i], NULL); 
    

    printf("\nSum:\n"); 
    for (i = 0; i < M; i++)
    { 
      for (j = 0; j < M; j++)
        printf("%d ", sum[i][j]); 
      
      printf("\n"); 
    } 

    return 0; 
} 

void* Sum(void* arg) 
{ 
	int i, j; 
	for (i = 0; i < M; i++)
		for (j = 0; j < M; j++) 
			sum[i][j] = A[i][j] + B[i][j]; 
} 

