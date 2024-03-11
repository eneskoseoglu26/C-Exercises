#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#define N 50

int main() {
	
	setlocale(LC_ALL,"turkish");
	
	char metin[N];
	int *dizi = (int*) calloc( 26,sizeof(int));
	int i,length,c;
	
	printf("Lütfen bir þeyler yazýn\n");
	gets(metin);
	length = strlen(metin);
	
	c = 0;
	
	for(i = 0; i <= length; i++) {
		
		if( (97 <= metin[i]) && (metin[i] <= 122) ) {
		
			dizi[metin[i] - 'a']++;
							
		}
		
	}
	
	printf("\n");
	
	for(i = 0; i < 26; i++) {
		
		if(dizi[i] > 0) {
		
			printf("%c = %d\n",i+97,dizi[i]);
		
		}
		
	}
			
	
return 0;
}
