#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	srand(time(NULL));
	
	int n,i,j;
	int *arr;
	
	n = rand() % 10 + 1;
	printf("Length of the array : %d\n",n);
	
	arr = (int*) malloc(n*sizeof(int));
	
	for(i = 0; i < n; i++) {
		
		arr[i] = rand() % 20 + 1;
		printf("%d ",arr[i]);
		
	}	
	
	j = rand() % n;
	printf("\nIndex that is going to deregistrate from array : %d\n",j);
	
	for(i = j; i < n-1; i++) {
		
		arr[i] = arr[i+1];
		
	} 

	for(i = 0; i < n-1; i++) {
		
		printf("%d ",arr[i]);
		
	}	
	
	
	
	return 0;
}


