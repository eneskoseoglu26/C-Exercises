#include <stdio.h>
#include <locale.h>
#define MAX 10

int AdMatrix[MAX][MAX];
int visited[MAX];

void DFS(int i, int vertex) {
	
	int j;
	
	printf("%d\n",i);
	visited[i] = 1;
	
	for(j = 0; j < vertex; j++) {
		
		if((visited[j] == 0) && (AdMatrix[i][j] == 1)) {
			
			DFS(j,vertex);
			
		}
		
	}
	
	
}

int main() {
	
	setlocale(LC_ALL,"turkish");
	
	int i,j;
	int dugum;
	
	printf("Düðüm sayýsý = ");
	scanf("%d",&dugum);
	printf("Komþuluk matrisini oluþturunuz.\n");
	
	for(i = 0; i < dugum; i++) {
		
		for(j = 0; j < dugum; j++) {
			
			printf("[%d][%d] = ",i,j);
			scanf("%d",&AdMatrix[i][j]);
			
		}
		
	}
	
	for(i = 0; i < dugum; i++) {
		
		visited[i] = 0;
		
	}
	
	DFS(0,dugum);
	
	
}
