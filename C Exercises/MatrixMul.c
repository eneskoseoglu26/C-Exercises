#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int main() {
	
	setlocale(LC_ALL,"turkish");
	srand(time(NULL));
	
	int **mata,**matb,**matc;
	int satira,sutuna,sutunb;
	int i,j,k;
	
	printf("A matrisinin satýr ve sütun sayýsý?\n");
	scanf("%d %d",&satira,&sutuna);
	
	printf("B matrisinin sütun sayýsý?\n");
	scanf("%d",&sutunb);
	
	mata = (int**) malloc(satira * sizeof(int*));
	
	if(mata == NULL) {
		
		printf("Yer ayrýlamadý!!");
		return -1;
		
	}
	
	for(i = 0; i < satira; i++) {
		
		mata[i] = (int*) malloc(sutuna * sizeof(int*));
		
		if(mata == NULL) {
		
		printf("Yer ayrýlamadý!!");
		return -1;
		
		}
		
	}
	
	printf("A matrisi :\n");
	
	for(i = 0; i < satira; i++) {
		
		for(j = 0; j < sutuna; j++) {
			
			mata[i][j] = rand() % 10;
			printf("%d\t",mata[i][j]);
			
		}
		
		printf("\n");
		
	}
	
	matb = (int**) malloc(sutuna * sizeof(int*));
	
	if(matb == NULL) {
		
		printf("Yer ayrýlamadý!!");
		return -1;
		
	}
	
	for(i = 0; i < sutuna; i++) {
		
		matb[i] = (int*) malloc(sutunb * sizeof(int*));
		
		if(matb == NULL) {
		
		printf("Yer ayrýlamadý!!");
		return -1;
		
		}
		
	}
	
	printf("\nB matrisi :\n");
	
	for(i = 0; i < sutuna; i++) {
		
		for(j = 0; j < sutunb; j++) {
			
			matb[i][j] = rand() % 10;
			printf("%d\t",matb[i][j]);
				
		}
		
		printf("\n");
		
	}
	
	matc = (int**) malloc(satira * sizeof(int*));
	
	if(matc == NULL) {
		
		printf("Yer ayrýlamadý!!");
		return -1;
		
	}
	
	for(i = 0; i < satira; i++) {
		
		matc[i] = (int*) malloc(sutunb * sizeof(int*));
		
		if(matc == NULL) {
		
		printf("Yer ayrýlamadý!!");
		return -1;
		
		}
		
	}
	
	printf("\nA x B sonucu oluþan matris :\n");
	
	for(i = 0; i < satira; i++) {
		
		for(j = 0; j < sutunb; j++) {
			
			matc[i][j] = 0;
			
			for(k = 0; k < sutuna; k++) {
				
				matc[i][j] = (mata[i][k] * matb[k][j]) + matc[i][j];
				
			}
			
			printf("%d\t",matc[i][j]);
			
		}
		
		printf("\n");
		
	}
	
	
	
	for(i = 0; i < satira; i++) {
		
		free(matc[i]);
		
	}
	
	free(matc);
	
	
	for(i = 0; i < sutuna; i++) {
		
		free(matb[i]);
		
	}
	
	free(matb);
	
	
	
	for(i = 0; i < satira; i++) {
		
		free(mata[i]);
		
	}
	
	free(mata);
	
	
return 0;	
}
