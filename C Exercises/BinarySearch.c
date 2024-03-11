#include <stdio.h>
#include <time.h>
#include <locale.h>
#define a 10

int main() {
	
	srand(time(NULL));
	setlocale(LC_ALL,"turkish");
	
	int dizi[a],first,last,mid;
	int n,i,x;
	
	printf("Dizinin eleman say�s� = ");
	scanf("%d",&n);
	
	printf("Dizinin elemanlar� :\n");
	
	for(i = 0; i < n; i++) {
		
		scanf("%d",&dizi[i]);
		
	}
	
	x = rand() % 10 + 1;
	
	printf("Dizide aranacak eleman = %d\n",x);
	
	first = 0;
	last = n - 1;
	mid = (last + first) / 2;
	
	while((first <= last) && (dizi[mid] != x)) {
		
		if(dizi[mid] < x) {
			
			first = mid + 1 ; 
			
		} else {
			
			last = mid - 1 ;
	
		}
	
		mid = (first + last) / 2;
 				
		
	}
	
	if(dizi[mid] == x) 
		printf("%d dizide bulunmaktad�r!",x);
	else
		printf("%d dizide bulunmamaktad�r!",x);	
	
	
return 0;
}
