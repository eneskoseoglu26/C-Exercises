#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int** CompressMatrix(int ** normal, int row, int col,int count);
void PrintCompressedMatrix(int**matrix,int row, int col);
void PrintMatrix(int**matrix,int row, int col);

int main() {
	
	setlocale(LC_ALL,"turkish");
	srand(time(NULL));
	
	int **mat,**compressed;
	int satir,sutun,sayac;
	int i,j;
	
	printf("Matrisin satýr sayýsý = ");
	scanf("%d",&satir);
	
	printf("Matrisin sütun sayýsý = ");
	scanf("%d",&sutun);
	
	mat = (int**) malloc(satir * sizeof(int));
	
	if(mat == NULL) {
		
		printf("Yer ayrýlamadý!!\n");
		return -1;
		
	}
	
	for(i = 0; i < satir; i++) {
		
		mat[i] = (int*) malloc(sutun * sizeof(int));
		
		if(mat[i] == NULL) {
			
			printf("Yer ayrýlamadý!!");
			return -1;
			
		}
		
	}
	
	sayac = 0;
	
	for(i = 0; i < satir; i++) {
		
		for(j = 0; j < sutun; j++) {
			
			printf("[%d][%d] = ",i,j);
			scanf("%d",&mat[i][j]);
			
			if(mat[i][j] !=0 ) {
		
				sayac++;
						
			}
			
		}
		
	}
	
	printf("Matris:\n");
	PrintMatrix(mat,satir,sutun);
	compressed = CompressMatrix(mat,satir,sutun,sayac);
	printf("Sýkýþtýrýlmýþ Matris:\n");
	PrintCompressedMatrix(compressed,3,sayac);
	
	
return 0;	

}

int** CompressMatrix(int ** normal, int row, int col,int count) {
	
		int **comp;
		int i,j,l;
	
		comp = (int**) calloc (3,sizeof(int*));		
	
		for(i = 0; i < 3; i++) {
		
		comp[i] = (int*) calloc(count,sizeof(int));
		
		}	
			
		l = 0;
	
		for(i = 0; i < row; i++) {
			
			for(j = 0; j < col; j++) {
				
				if(normal[i][j] != 0) {
					
					comp[0][l] = i;
					comp[1][l] = j;			
					comp[2][l] = normal[i][j];
					l++;
					
				}
				
			}
			
		}
			
	return comp;
	
}

void PrintCompressedMatrix(int**matrix,int row, int col) {
	
	int i,j;
	
	for(i = 0; i < row; i++) {
		
		if(i==0) {
			
			printf("Satýr=> ");
			
		}
		
		if(i==row-1){
			
			printf("Deðer=> ");
			
		}
		
		for(j = 0; j < col; j++) {
			
			printf("%d\t",matrix[i][j]);
			
		}
	
		printf("\n");
		
		if(i==0) {
			
			printf("Sütun=> ");
			
		}
		
		
		
	}
	
}

void PrintMatrix(int**matrix,int row, int col) {
	
	int i,j;
	
	for(i = 0; i < row; i++) {

		for(j = 0; j < col; j++) {
			
			printf("%d\t",matrix[i][j]);
			
		}
	
		printf("\n");
		
	}
	
}
