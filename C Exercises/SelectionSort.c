#include <stdio.h>
#include <locale.h>
#define SIZE 10

int main () {
	
	setlocale(LC_ALL,"turkish");
	
	int dizi[SIZE],element,index,swapped;
	int i,j,tmp;
	
	printf("Dizinin eleman sayýsý = ");
	scanf("%d",&element);
	
	printf("Dizinin elemanlarý :\n");
	
	for(i = 0; i < element; i++) { 
	
		printf("%d. eleman = ",i+1);
		scanf("%d",&dizi[i]);
	
	}
	
	printf("\nDizinin sýrasýz hali :\n");
	
	for(i = 0; i < element; i++) {
	
		printf("%d\t",dizi[i]);
			
	}
	
	for(i = 0; i < element-1; i++) {
		
		index = i;
		swapped = 0;
	
		for(j = i+1; j < element; j++) {
			
			if(dizi[index] < dizi[j]) {
				
				index = j;
				swapped = 1;
				
			}
			
		}
		
		if(swapped == 1) {
	
			tmp = dizi[i];
			dizi[i] = dizi[index];
			dizi[index] = tmp;
		
		}

	}
	
	printf("\nDizinin sýralý hali :\n");
	
	for(i = 0; i < element; i++) {
	
		printf("%d\t",dizi[i]);
			
	}
	
	
return 0; 	
}
