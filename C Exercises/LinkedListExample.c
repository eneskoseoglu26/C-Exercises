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
		
		printf("Yapmak istedi�iniz i�lem nedir?\n1-Kay�t Ekleme\n2-Kay�t Silme\n3-Kay�tlar� Yazd�rma\n0-��k��\n");
		scanf("%d",&secim);
		
		switch(secim) {
			
			case 0:
					printf("��k�� Yapt�n�z!!\n");
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
					printf("Ge�ersiz say� girdiniz l�tfen tekrar deneyiniz.\n");
					
									
		}
		
		
	}
	
	
return 0;	
}

EMPLOYEE* CreateEmployee() {
	
	EMPLOYEE *new_employee = (EMPLOYEE*) malloc(sizeof(EMPLOYEE));
	
	printf("S�ras�yla => Ad,Soyad ve ID bilgilerini giriniz\n");
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
	
	printf("Silmek istedi�iniz ki�inin ID'sini giriniz : ");
	scanf("%d",&id);
	
	if((*root)->id == id) {
		
		tmp = *root;
		*root = (*root)->next;
		free(tmp);
		printf("%d ID'li kay�t silindi!!\n",id);
	
	} else {
		
		tmp = *root;
		
		while((tmp->next != NULL) && (tmp->next->id != id)) {
			
			tmp = tmp->next;
			
		}
		
		if(tmp->next != NULL) {
			
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp2);
			printf("%d ID'li kay�t silindi!!\n",id);
			
		} else {
			
			printf("%d ID''li kay�t bulunamad��� i�in silinemedi!!\n",id);
			
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

