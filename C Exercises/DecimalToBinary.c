#include <stdio.h>
#define n 8

int main() {
	
	int sayi,tmp;
	int i = 0,j;
	char binary[n];
	
	printf("Bir sayý giriniz: ");
	scanf("%d",&sayi);

	tmp = sayi;

	if(sayi < 0) 
		sayi = -sayi;
	
	
	while(sayi > 0) {
		
		binary[i] = sayi % 2;
		sayi = sayi / 2;
		i++;
		
	}
	
	
	for(j = i; j < n; j++) {
		
		binary[j] = 0;
	
	}
	
	if(tmp < 0) {
		
		j = 0;
		
		while(binary[j] != 1) {
			
			j++;
			
		}
		
		for(i = j+1; i < n; i++) {
			
			if(binary[i] == 0) {
				
				binary[i] = 1;
				
			} else {
				
				binary[i] = 0;
				
			}
			
		}
			
	}
	
	printf("Decimal = %d  --> Binary = ",tmp);
	
	for(j = n-1; j >= 0; j--) {
		
		printf("%d",binary[j]);
		
	}
	

	 	
return 0;	
}
