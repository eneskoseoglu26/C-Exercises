#include <stdio.h>
#include <stdlib.h>

int* ConcatenateArrays(int *a, int size1, int *b, int size2);
void PrintArray(int *a,int n);

int main() {
	
	int a[] = {12,5,-1,23,6,7};
	int b[] = {13,6,-2,1};
	int *c;
	int sizeA,sizeB;
	
	sizeA = sizeof(a) / sizeof(a[0]);
	sizeB = sizeof(b) / sizeof(b[0]);
	
	printf("Elements of the Array A : ");
	PrintArray(a,sizeA);
	printf("Elements of the Array B : ");
	PrintArray(b,sizeB);
	c = ConcatenateArrays(a,sizeA,b,sizeB);
	printf("Elements of the Concatenated Array : ");
	PrintArray(c,sizeA+sizeB);
	
	return 0;
}

void PrintArray(int *a,int n) {
	
	int i;
	
	for(i = 0; i < n; i++) {
		
		printf("%d ",a[i]);
		
	}
	
	printf("\n");
	
}

int* ConcatenateArrays(int *a, int size1, int *b, int size2) {
	
	int *c;
	int i;
	
	c = (int*) malloc((size1+size2)*sizeof(int));
	
	if(c == NULL) {
		
		printf("Memory did not allocated!\n");
		return -1;
		
	}
	
	for(i = 0; i < size1; i++) {
		
		c[i] = a[i];
		
	}
	
	for(i = 0; i < size2; i++) {
		
		c[size1+i] = b[i];
		
	}
	
	return c;
	
}
