#include <stdio.h>
#include <time.h>
#define N 20

int main() {
	
	srand(time(NULL));
	
	int dizi[N],n;
	int i,j;
	int count;
	
	printf("Boyut = ");
	scanf("%d",&n);
	
	for(i = 0; i < n; i++) {
		
		dizi[i] = rand() % 3;
		printf("%d ",dizi[i]);
			
	}
	
	i = 0;
		
	while((i < (n/2)) && (count <= (n/2))) {
		
		count = 0;
		
		for(j = 0; j < n; j++) {
			
			if(dizi[i] == dizi[j]) {
				
				count++;
				
			}
			
		}
		
		i++;
		
	}
	
	if(i == (n/2)) {
		
		printf("\nNo Majority Element\n");
		
	} else {
		
		printf("\nMajority Element: %d\n",dizi[i-1]);
		
	}
	
	
	return 0;
}
