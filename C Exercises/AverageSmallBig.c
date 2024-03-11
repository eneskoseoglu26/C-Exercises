#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	
	srand(time(NULL));
	
	int n,i,avg,small,big,equal;
	int *arr;
	
	avg = small = big = equal = 0;
	
	printf("Length of array : ");
	scanf("%d",&n);
	
	arr = (int*) malloc(n * sizeof(int));
	
	for(i = 0; i < n; i++) {
		
		arr[i] = rand() % 50 + 1;
		avg = arr[i] + avg;
		printf("%d ",arr[i]);
		
	}
	
	
	avg = avg / n;
	
	for(i = 0; i < n; i++) {
		
		if(avg > arr[i]) {
			
			small++;
			
		} else if(avg < arr[i]) {
			
			big++;
			
		} else {
			
			equal++;
			
		}
			
		
	}
	
	printf("\nAverage : %d\nSmall Than Average : %d\nBig Than Average : %d\nEqual to Average : %d",avg,small,big,equal);
	
	free(arr);
	
	
	return 0;
}
