#include <stdio.h>
#include <locale.h>

int main () {

	setlocale(LC_ALL,"turkish");
	
	char dizi[100],tmp;
	int i,harf;
	
	printf("Ad�n�z� giriniz : ");
	gets(dizi);
	
	harf = 0;
	
	while( dizi[harf] != '\0' ) {
		
		harf++;
		
	}	

	for( i = 0; i < (harf/2); i++ ) {
		
		tmp = dizi[i];
		dizi[i] = dizi[harf-i-1];
		dizi[harf-i-1] = tmp;
	
	}

	printf("Ad�n�z�n tersten hali : %s\n",dizi);
	
return 0;	
}
