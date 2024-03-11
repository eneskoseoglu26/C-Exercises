#include <stdio.h>
#include <time.h>
#define N 10

int main() {
	
	srand(time(NULL));
	
	int matris[N][N],Tmatris[N][N],n,m;
	int i,j;
	
	printf("Matrisin satir ve sutun sayisi :\n");
	scanf("%d%d",&n,&m);
	
	printf("Matris:\n");
	
	for(i = 0; i < n; i++) {
		
		for(j = 0; j < m; j++) {
			
			matris[i][j] = rand() % 10;
			printf("%d ",matris[i][j]);
			
		}
		
		printf("\n");
		
	}
	
	for(i = 0; i < m; i++) {
		
		for(j = 0; j < n; j++) {
		
			Tmatris[i][j] = matris[j][i];
			
		}
		
	}
	
	
	printf("\nGirilen Matrisin Transpozu:\n");
	
	for(i = 0; i < m; i++) {
		
		for(j = 0; j < n; j++) {
			
			printf("%d ",Tmatris[i][j]);
			
		}
		
		printf("\n");
		
	}
	
	return 0;
}
