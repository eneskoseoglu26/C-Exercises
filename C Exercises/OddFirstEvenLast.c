#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	
	srand(time(NULL));
	
	int n,i,j,tmp;
	int *arr;
	
	printf("Length of array : ");
	scanf("%d",&n);
	
	arr = (int*) malloc(n * sizeof(int));
	
	for(i = 0; i < n; i++) {
		
		arr[i] = rand() % 20 + 1;
		printf("%d ",arr[i]);
		
	}
	
	i = 0;
	j = n-1;
	
	while(i < j) {
		
		while(i < j && (arr[i] % 2 == 1)) {
			
			i++;
			
		}
		
		while(j > i && (arr[j] % 2 == 0)) {
			
			j--;
			
		}
		
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		i++;
		j--;
		
		
		
	}
	
	printf("\n");
		
	for(i = 0; i < n; i++) {
		
		printf("%d ",arr[i]);
		
	}	
		
	free(arr);
	
	
	return 0;
}
