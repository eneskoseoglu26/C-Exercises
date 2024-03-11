/* 
Kullanýcý tarafýndan oluþturulan matrisin her bir sütununun toplamýný veren kod.
*/

#include <stdio.h>
#define N 10

int main() { 

	int matris[N][N];
	int sat,sut;
	int i,j,toplam;
	
	printf("Olusturacaginiz matrisin satir ve sutun sayilari :\n");
	scanf("%d %d",&sat,&sut);
	
	printf("Matrisinizin elemanlari :\n");
	
	for( i = 0; i < sat; i++) {
		
		for( j = 0; j < sut; j++) {
		
			printf("[%d][%d] = ", i , j);	
			scanf("%d",&matris[i][j]);	
		}
		
	}
	
	printf("Olusturdugunuz matris :\n");
	
	for( i = 0; i < sat; i++) {
		
		for( j = 0; j < sut; j++) {
		
			printf("%d ",matris[i][j]);		
		
		}
		
		printf("\n");
		
	}
		
	for( j = 0; j < sut; j++) {
		
		toplam = 0;
	
		for(i = 0; i < sat; i++) {
				
			toplam = toplam + matris[i][j];
			
		}
		printf("%d ",toplam);
	}


return 0;
} 
