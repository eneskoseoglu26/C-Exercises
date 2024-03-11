#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

int main () {
	
	setlocale(LC_ALL,"turkish");
	
	int number,edge;
	int *list;
	int i,j;
	
	printf("Bir sayý giriniz = ");
	scanf("%d",&number);
	
	edge = sqrt(number);
	
	list = (int*) malloc(number * sizeof(int));
	
	for(i = 1; i <= number; i++) {
		
		list[i-1] = i;
	//	printf("%d ",list[i-1]);
		
	}	
	
	i = 2;
	list[0] = 0;
	
	while(i <= edge) {
		
		if(list[i-1] != 0) {
		
			for(j = 2; j <= number/i; j++) {
			
				list[(j*i)-1] = 0;
			
			}
		
		}	
		
		i++;
		
	}
	
	printf("%d kadar olan asal sayýlar þunlardýr:\n",number);
	
	for(i = 1; i < number; i++) {
		
		if(list[i] != 0) {
		
			printf("%d ",list[i]);
		
		}
		
	}	
	
	
	
return 0;	
}
