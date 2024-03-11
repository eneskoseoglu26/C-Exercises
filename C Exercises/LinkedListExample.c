#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct employee {
	
	char name[20];
	char surname[20]; 
	int id;
	struct employee *next;
	
}EMPLOYEE;

EMPLOYEE* CreateEmployee();
void AddEmployee(EMPLOYEE **root);
void DeleteEmployee(EMPLOYEE **root);
void PrintEmployees(EMPLOYEE *root,void (*fptr)(EMPLOYEE*));
void PrintNameFirst(EMPLOYEE *tmp2);
void PrintSurnameFirst(EMPLOYEE *tmp2);
void PrintIDFirst(EMPLOYEE *tmp2);

int main() {
	
	setlocale(LC_ALL,"turkish");
	
	EMPLOYEE *head = NULL;
	int secim=1;	
	
	while(secim) {
		
		printf("Yapmak istediðiniz iþlem nedir?\n1-Kayýt Ekleme\n2-Kayýt Silme\n3-Kayýtlarý Yazdýrma\n0-Çýkýþ\n");
		scanf("%d",&secim);
		
		switch(secim) {
			
			case 0:
					printf("Çýkýþ Yaptýnýz!!\n");
					break;
					
			case 1:
					AddEmployee(&head);
					break;
					
			case 2:
					DeleteEmployee(&head);		
					break;
			
			case 3:
					PrintEmployees(head,PrintIDFirst);
					break;
			
			default:
					printf("Geçersiz sayý girdiniz lütfen tekrar deneyiniz.\n");
					
									
		}
		
		
	}
	
	
return 0;	
}

EMPLOYEE* CreateEmployee() {
	
	EMPLOYEE *new_employee = (EMPLOYEE*) malloc(sizeof(EMPLOYEE));
	
	printf("Sýrasýyla => Ad,Soyad ve ID bilgilerini giriniz\n");
	scanf("%s %s %d",new_employee->name,new_employee->surname,&new_employee->id);
	new_employee->next = NULL;
	return new_employee;
}

void AddEmployee(EMPLOYEE **root) {
	
	EMPLOYEE *new_employee = CreateEmployee();
	
	new_employee->next = *root;
	*root = new_employee;
	
}

void DeleteEmployee(EMPLOYEE **root) {
	
	int id;
	EMPLOYEE *tmp;
	EMPLOYEE *tmp2;
	
	printf("Silmek istediðiniz kiþinin ID'sini giriniz : ");
	scanf("%d",&id);
	
	if((*root)->id == id) {
		
		tmp = *root;
		*root = (*root)->next;
		free(tmp);
		printf("%d ID'li kayýt silindi!!\n",id);
	
	} else {
		
		tmp = *root;
		
		while((tmp->next != NULL) && (tmp->next->id != id)) {
			
			tmp = tmp->next;
			
		}
		
		if(tmp->next != NULL) {
			
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp2);
			printf("%d ID'li kayýt silindi!!\n",id);
			
		} else {
			
			printf("%d ID''li kayýt bulunamadýðý için silinemedi!!\n",id);
			
		}
		
		
	}
	
	
	
}

void PrintEmployees(EMPLOYEE *root,void (*fptr)(EMPLOYEE*)) {
	
	EMPLOYEE *tmp; 
	
	tmp = root;
	
	while(tmp != NULL) {
		
		fptr(tmp);
		tmp = tmp->next;
		
	}
	
	
}

void PrintNameFirst(EMPLOYEE *tmp2) {
	
	printf("%s %s %d\n",tmp2->name,tmp2->surname,tmp2->id);
	
}

void PrintSurnameFirst(EMPLOYEE *tmp2) {
	
	printf("%s %s %d\n",tmp2->surname,tmp2->name,tmp2->id);
	
}

void PrintIDFirst(EMPLOYEE *tmp2) {
	
	printf("%d %s %s\n",tmp2->id,tmp2->name,tmp2->surname);
	
}

