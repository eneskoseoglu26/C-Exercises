#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main() {
	
	setlocale(LC_ALL,"turkish");
	srand(time(NULL));
	
	int **mat;
	int satir,sutun;
	int i,j,tmp;
	int ch1,ch2;
	
	printf("Matrisin sat�r say�s� = ");
	scanf("%d",&satir);
	
	printf("Matrisin s�tun say�s� = ");
	scanf("%d",&sutun);
	
	mat = (int**) malloc(satir * sizeof(int*));
	
	if( mat == NULL) {
		
		printf("Yer ayr�lamad�!!\n");
		return -1;
		
	}
	
	for(i = 0; i < satir; i++) {
		
		mat[i] = (int*) malloc(sutun * sizeof(int));
		
	}
	
	printf("\n");
	
	for(i = 0; i < satir; i++) {
		
		for(j = 0; j < sutun; j++) {
			
			mat[i][j] = rand() % 10 + 1;
			printf("%d\t",mat[i][j]);
						
		}
		
		printf("\n");
		
	}
	
	printf("\nDe�i�tirmek istedi�iniz s�tun numaralar� :\n");
	scanf("%d %d",&ch1,&ch2);
	
	for(i = 0; i < satir; i++) {
		
		tmp = mat[i][ch1];
		mat[i][ch1] = mat[i][ch2];
		mat[i][ch2] = tmp;
		
	}
	
	printf("\nMatrisin %d. ve %d. s�tunlar�n�n yer de�i�tirilmi� hali :\n",ch1,ch2);
	
	for(i = 0; i < satir; i++) {
		
		for(j = 0; j < sutun; j++) {
			
			printf("%d\t",mat[i][j]);
						
		}
		
		printf("\n");
		
	}
	
	
	
	for(i = 0; i < satir; i++) {
		
		free(mat[i]);
		
	}
	
	free(mat);
	
return 0;	
}
