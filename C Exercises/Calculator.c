// HESAP MAKINESI

#include <stdio.h>
#include <time.h>
#include <locale.h>

int main() {
	
	srand(time(NULL));
	setlocale(LC_ALL,"Turkish");
	
	int sayi1,sayi2;
	char sec;
	
	printf("Merhaba Hesap Makinesi Konsoluna Ho�geldiniz.\nL�tfen yapmak istedi�iniz i�lemin KARAKTER�N� giriniz :\nToplama => +\n��karma => -\n�arpma => *\nB�lme => /\nMod Alma => %%\nKare Alma => ^\n��k�� => C\n\nSe�im => ");
	scanf("%c",&sec);
	
	while(sec != 'C') {
		
		switch(sec) {
			
			case '+' :
					printf("\n�ki say� giriniz :\n");
					scanf("%d%d",&sayi1,&sayi2);
					printf("%d + %d = %d\n",sayi1,sayi2,sayi1+sayi2);
					break;
			
			case '-' :
					printf("\n�ki say� giriniz :\n");
					scanf("%d%d",&sayi1,&sayi2);
					printf("%d - %d = %d\n",sayi1,sayi2,sayi1-sayi2);
					break;
			
			
			case '*' :
					printf("\n�ki say� giriniz :\n");
					scanf("%d%d",&sayi1,&sayi2);
					printf("%d * %d = %d\n",sayi1,sayi2,sayi1*sayi2);
					break;
			
			case '/' :
					printf("\n�ki say� giriniz :\n");
					scanf("%d%d",&sayi1,&sayi2);
					printf("%d * %d = %d\n",sayi1,sayi2,sayi1/sayi2);
					break;
			
			case '%' :
					printf("\n�ki say� giriniz :\n");
					scanf("%d%d",&sayi1,&sayi2);
					printf("%d % %d = %d\n",sayi1,sayi2,sayi1%sayi2);
					break;
			
			case '^' :
					printf("\nBir say� giriniz :\n");
					scanf("%d",&sayi1);
					printf("%d^2 = %d\n",sayi1,sayi1*sayi1);
					break;
			
			default : 
					printf("\nGE�ERS�Z bir karakter girdiniz!L�tfen tekrar deneyiniz.\n");	
			
		}
		
		printf("\nL�tfen yapmak istedi�iniz i�lemin KARAKTER�N� giriniz :\nToplama => +\n��karma => -\n�arpma => *\nB�lme => /\nMod Alma => %\nKare Alma => ^\n��k�� => C\n\nSe�im => ");
		scanf(" %c",&sec);
		
	}
	
	printf("\nHesap Makinesini Konsolundan ��k�� Yapt�n�z. G�r��mek �zere!\n");
	
	return 0;
}

