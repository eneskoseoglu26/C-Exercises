#include <stdio.h>
#include <time.h>
#define N 20

int main() {
	
	int dizi[N];
	int n,i,j,k;
	int res,flag;
	
	printf("Dizinin eleman sayisi : ");
	scanf("%d",&n);
	
	printf("Dizinin elemanlari :\n");
	for(i = 0; i < n; i++) {
		
		scanf("%d",&dizi[i]);
		
	}
	
	printf("Dizi : ");
	for(i = 0; i < n; i++) {
		
		printf("%d ",dizi[i]);
		
	}
	
	i = 0;
	j = 0;
	res = dizi[i];
	
	while((i < n-1) && (res != 0)) {
		
		j = i + 1;
		flag = 0;
		res = 0;
		
		while((j < n) && (flag == 0)) {
			
			res += dizi[j];
			if(res == 0) {
				
				flag = 1;
				
			} else {
				
				j++;
				
			}
			
		}
		
		i++;
		
	}
	
	if(res == 0) {
		
		printf("\nToplami 0 olan Subarray var, Start : %d End: %d\n",i,j);		
		
	} else {
		
		printf("\nToplami 0 olan Subarray yok!\n");
	
	}
	
		
	return 0;
}
