#include <stdio.h>
#include <time.h>
#define N 10

void PrintMatrix(int mat[N][N], int m, int n);
void PrintFloatMatrix(float mat[N][N], int m, int n);
void MatrixMultiplication(int mat1[N][N], int mat2[N][N], int mat3[N][N], int m, int n, int r);
void MatrixSummation(int mat1[N][N], int mat2[N][N], int mat3[N][N], int m, int n);
void ElementOfMatrix(int mat[N][N], int m ,int n);
int MinOrMaxElementOfMatrix(int mat[N][N], int m, int n, int mode);
void MatrixNormalization(int mat[N][N], float mat2[N][N], int m, int n);

int main() {
	
	srand(time(NULL));
	
	int m1[N][N],m2[N][N],m3[N][N],m,n,r,s;
	int secim;
	float m4[N][N];
	
	printf("0) Cikis\n1) Matrisleri Toplama\n2) Matrisleri Carpma\n3) Matrisin Normalizasyonu\n");
	scanf("%d",&secim);
	
	while(secim != 0) {
		
		switch(secim) {
			
			case 1:
				
				printf("A matrisinin satir ve sutun sayisi :\n");
				scanf("%d%d",&m,&n);
	
				ElementOfMatrix(m1,m,n);
				
				printf("A matrisi :\n");
				PrintMatrix(m1,m,n);
				
				printf("B matrisinin satir ve sutun sayisi :\n");
				scanf("%d%d",&r,&s);
	
				ElementOfMatrix(m2,m,n);
				
				printf("B matrisi :\n");
				PrintMatrix(m2,r,s);
				
				MatrixSummation(m1,m2,m3,m,n);
				printf("A + B :\n");
				PrintMatrix(m3,m,n);
				
				break;
					
			case 2:	
			
				printf("A matrisinin satir ve sutun sayisi :\n");
				scanf("%d%d",&m,&n);
	
				ElementOfMatrix(m1,m,n);
				
				printf("A matrisi :\n");
				PrintMatrix(m1,m,n);
				
				printf("B matrisinin satir ve sutun sayisi :\n");
				scanf("%d%d",&r,&s);
	
				ElementOfMatrix(m2,m,n);
				
				printf("B matrisi :\n");
				PrintMatrix(m2,r,s);
				
				MatrixMultiplication(m1,m2,m3,m,n,s);
				printf("A x B :\n");
				PrintMatrix(m3,m,s);
				
				break;
				
			case 3:
			
				printf("Matrisinin satir ve sutun sayisi :\n");
				scanf("%d%d",&m,&n);
	
				ElementOfMatrix(m1,m,n);
				
				printf("Matris :\n");
				PrintMatrix(m1,m,n);
				
				MatrixNormalization(m1,m4,m,n);
				
				printf("Normalize edilmis Matris :\n");
				PrintFloatMatrix(m4,m,n);
					
				break;
				
			default:
					
				printf("Lutfen gecerli bir sayi girin!\n");
				
			
		}
		
		printf("0) Cikis\n1) Matrisleri Toplama\n2) Matrisleri Carpma\n3) Matrisin Normalizasyonu\n");
		scanf("%d",&secim);
		
	}
	
	printf("Cikis yaptiniz!\n");

	return 0;
}

void PrintMatrix(int mat[N][N],int m,int n) {
	
	int i,j;
	
	for(i = 0; i < m; i++) {
		
		for(j = 0; j < n; j++) {
			
			printf("%d ",mat[i][j]);
		
		}
	
		printf("\n");
			
	}
	
	printf("\n");
	
}

void PrintFloatMatrix(float mat[N][N], int m, int n) {
	
	int i,j;
	
	for(i = 0; i < m; i++) {
		
		for(j = 0; j < n; j++) {
			
			printf("%f ",mat[i][j]);
		
		}
	
		printf("\n");
			
	}
	
	printf("\n");
	
	
}

void MatrixMultiplication(int mat1[N][N], int mat2[N][N], int mat3[N][N], int m, int n, int r) {
	
	int i,j,k;
	
	for(i = 0; i < m; i++) {
		
		for(j = 0; j < r; j++) {
			
			mat3[i][j] = 0;
			
			for(k = 0; k < n; k++) {
				
				mat3[i][j] += (mat1[i][k] * mat2[k][j]);
				
			}
		
		}
		
	}
	
	
}

void MatrixSummation(int mat1[N][N], int mat2[N][N], int mat3[N][N], int m, int n) {
	
	int i,j;
	
	for(i = 0; i < m; i++) {
		
		for(j = 0; j < n; j++) {
			
			mat3[i][j] = mat1[i][j] + mat2[i][j];
			
		}
		
 	}
	
	 
}

void ElementOfMatrix(int mat[N][N], int m ,int n) {
	
	int i,j;	
	
	for(i = 0; i < m; i++) {
		
		for(j = 0; j < n; j++) {
			
			mat[i][j] = rand() % 10 + 1;
			
		}
		
	}
	
}

int MinOrMaxElementOfMatrix(int mat[N][N], int m, int n, int mode) {
	
	int i,j;
	int MinMax = mat[0][0];
	
	if(mode == 1) {
		
		for(i = 0; i < m; i++) {
		
			for(j = 0; j < n; j++) {
			
				if(MinMax > mat[i][j]) {
					
					MinMax = mat[i][j];
					
				}
			
			}
			
		}
		
	} else {
		
		for(i = 0; i < m; i++) {
		
			for(j = 0; j < n; j++) {
			
				if(MinMax < mat[i][j]) {
					
					MinMax = mat[i][j];
					
				}
			
			}
			
		}
			
	}
	
	return MinMax;
	
}

void MatrixNormalization(int mat[N][N], float mat2[N][N], int m, int n) {
	
	int i,j;
	
	for(i = 0; i < m; i++) {
		
		for(j = 0; j < n; j++) {
			
			mat2[i][j] = (float)(mat[i][j] - MinOrMaxElementOfMatrix(mat,m,n,1)) / (MinOrMaxElementOfMatrix(mat,m,n,2) - MinOrMaxElementOfMatrix(mat,m,n,1));

		}
		
	}
	
}
