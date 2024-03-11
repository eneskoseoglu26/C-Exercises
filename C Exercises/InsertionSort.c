#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void InsertionSort(int dizi[],int n);
void yazdir(int dizi[],int n);

int main () {
	
	setlocale(LC_ALL,"turkish");
	srand(time(NULL));
	
	int *list;
	int n;
	int i,j,tmp,control;
	
	printf("Dizinin eleman sayýsý = ");
	scanf("%d",&n);
	
	list = (int*) malloc (n * sizeof(int));
	
	for(i = 0; i < n; i++) {
		
		list[i] = rand() % 20 + 1;
		
	}
	printf("\nDizinin sýrasýz hali :\n");
	yazdir(list,n);
	
	InsertionSort(list,n);
	
	printf("\nDizinin sýralý hali :\n");
	yazdir(list,n);
	
return 0;	

}

void InsertionSort(int dizi[],int n) {
	
	int i,j,control,tmp;
	
	for(i = 1; i < n; i++) {
		
		j = i-1;
		control = i;
			
		while(j >= 0 && dizi[control] < dizi[j]) {
			
			tmp = dizi[j];
			dizi[j] = dizi[control];
			dizi[control] = tmp; 
			control = j;
			j--;
			
		}
		
	}
	
}

void yazdir(int dizi[],int n) {
	
	int i;
	
	for(i = 0; i < n; i++) {
		
		printf("%d\t",dizi[i]);
		
	}
	
	
}
