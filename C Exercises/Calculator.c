// HESAP MAKINESI

#include <stdio.h>
#include <time.h>
#include <locale.h>

int main() {
	
	srand(time(NULL));
	setlocale(LC_ALL,"Turkish");
	
	int sayi1,sayi2;
	char sec;
	
	printf("Merhaba Hesap Makinesi Konsoluna Hoþgeldiniz.\nLütfen yapmak istediðiniz iþlemin KARAKTERÝNÝ giriniz :\nToplama => +\nÇýkarma => -\nÇarpma => *\nBölme => /\nMod Alma => %%\nKare Alma => ^\nÇýkýþ => C\n\nSeçim => ");
	scanf("%c",&sec);
	
	while(sec != 'C') {
		
		switch(sec) {
			
			case '+' :
					printf("\nÝki sayý giriniz :\n");
					scanf("%d%d",&sayi1,&sayi2);
					printf("%d + %d = %d\n",sayi1,sayi2,sayi1+sayi2);
					break;
			
			case '-' :
					printf("\nÝki sayý giriniz :\n");
					scanf("%d%d",&sayi1,&sayi2);
					printf("%d - %d = %d\n",sayi1,sayi2,sayi1-sayi2);
					break;
			
			
			case '*' :
					printf("\nÝki sayý giriniz :\n");
					scanf("%d%d",&sayi1,&sayi2);
					printf("%d * %d = %d\n",sayi1,sayi2,sayi1*sayi2);
					break;
			
			case '/' :
					printf("\nÝki sayý giriniz :\n");
					scanf("%d%d",&sayi1,&sayi2);
					printf("%d * %d = %d\n",sayi1,sayi2,sayi1/sayi2);
					break;
			
			case '%' :
					printf("\nÝki sayý giriniz :\n");
					scanf("%d%d",&sayi1,&sayi2);
					printf("%d % %d = %d\n",sayi1,sayi2,sayi1%sayi2);
					break;
			
			case '^' :
					printf("\nBir sayý giriniz :\n");
					scanf("%d",&sayi1);
					printf("%d^2 = %d\n",sayi1,sayi1*sayi1);
					break;
			
			default : 
					printf("\nGEÇERSÝZ bir karakter girdiniz!Lütfen tekrar deneyiniz.\n");	
			
		}
		
		printf("\nLütfen yapmak istediðiniz iþlemin KARAKTERÝNÝ giriniz :\nToplama => +\nÇýkarma => -\nÇarpma => *\nBölme => /\nMod Alma => %\nKare Alma => ^\nÇýkýþ => C\n\nSeçim => ");
		scanf(" %c",&sec);
		
	}
	
	printf("\nHesap Makinesini Konsolundan Çýkýþ Yaptýnýz. Görüþmek üzere!\n");
	
	return 0;
}

