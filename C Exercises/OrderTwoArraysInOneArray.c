#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *a,int n);
int* OrderTwoArraysInOneArray(int *ar1, int size1, int *ar2, int size2);

int main() {
	
	int a[] = {-8,-1,10,12,27,30,52,66,72,73};
	int b[] = {-10,-3,0,15,25,32,44,100};
	int *c;
	int sizeA,sizeB;
	
	sizeA = sizeof(a) / sizeof(a[0]);
	sizeB = sizeof(b) / sizeof(b[0]);
	
	printf("Elements of the Array A : ");
	PrintArray(a,sizeA);
	printf("Elements of the Array B : ");
	PrintArray(b,sizeB);
	c = OrderTwoArraysInOneArray(a,sizeA,b,sizeB);
	printf("Elements of the Two Ordered Arrays in One Array : ");
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

int* OrderTwoArraysInOneArray(int *ar1, int size1, int *ar2, int size2) {
	
	int *ar3;
	int i,j;
	
	ar3 = (int*) malloc((size1+size2) * sizeof(int));
	
	if(ar3 == NULL) {
		
		printf("Memory did not allocated!\n");
		return -1;
		
	}
	
	i = j = 0;
	
	while((i < size1) && (j < size2)) {
		
		if(ar1[i] < ar2[j]) {
			
			ar3[i+j] = ar1[i];
			i++;
			
		} else {
			
			ar3[i+j] = ar2[j];
			j++;
			
		}
		
	}
	
	if(i == size1) {
		
		for(i = j; i < size2; i++) {
			
			ar3[size1+i] = ar2[i];
			
		}
		
	} else {
		
		for(j = i; j < size1; j++) {
			
			ar3[size2+j] = ar1[j];
			
		}
		
	}
	
	return ar3;
	
}
