#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int *a,int m);
void EnterElements(int *a,int m);
void PrintArray(int *a,int m);

int main() {
	
	srand(time(NULL));
	int *ar,n;
	
	printf("Length of the Array : ");
	scanf("%d",&n);
	
	ar = (int*) malloc(n*sizeof(int));
	
	if(ar == NULL) {
		
		printf("Memory did not allocated!\n");
		return -1;
		
	}
	
	EnterElements(ar,n);
	printf("Array : ");
	PrintArray(ar,n);
	BubbleSort(ar,n);
	printf("Sorted Array : ");
	PrintArray(ar,n);
	
	free(ar);	
	
	return 0;
}

void EnterElements(int *a,int m) {
	
	int i;
	
	for(i = 0; i < m; i++) {
		
		a[i] = rand() % 20;
				
	}
	
}

void PrintArray(int *a,int m) {
	
	int i;
	
	for(i = 0; i < m; i++) {
		
		printf("%d ",a[i]);
				
	}
	
	printf("\n");
	
}

void BubbleSort(int *a,int m) {
	
	int i,swapped=1;
	int tmp;
	
	while(swapped) {
		
		swapped = 0;
		
		for(i = 0; i < m-1; i++) {
			
			if(a[i] > a[i+1]) {
				
				tmp = a[i];
				a[i] = a[i+1];
				a[i+1] = tmp;	
				swapped = 1;
			
			}
			
		}
		
	}

}
