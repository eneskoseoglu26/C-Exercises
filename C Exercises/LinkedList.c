#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node{
	
	int data;
	struct node *next;
	
}NODE;

NODE* CreateNode(int x);
NODE* SearchNode(NODE *root);
int HowManyNodes(NODE *root);
int HowManyNodesV2(NODE *root);
void Enqueue(NODE **root,int x);
void Dequeue(NODE **root);
void StackPush(NODE **root,int x);
void StackPop(NODE **root);
void AddFront(NODE **root,int x);
void Traverse(NODE *root);
void AddLast(NODE **root,int x);
void AddMiddle(NODE **root,int x);
void DeleteFirst(NODE **root);
void DeleteLast(NODE **root);
void DeleteMiddle(NODE **root);

int main() {

	setlocale(LC_ALL,"turkish");
	
	int i;
	NODE *head = NULL;
	NODE *tmp = NULL;
	
/*	Enqueue(&head,16);
	Traverse(head);
	Enqueue(&head,6);
	Traverse(head);
	Enqueue(&head,10);
	Traverse(head);
	Enqueue(&head,21);
	Traverse(head);
	Dequeue(&head);
	Traverse(head);
	Dequeue(&head);
	Traverse(head);
	Dequeue(&head);
	Traverse(head);
	Dequeue(&head);
	Traverse(head);
*/	
	
	

/*	StackPush(&head,7);
	Traverse(head);
	StackPush(&head,21);
	Traverse(head);
	StackPush(&head,14);
	Traverse(head);
	StackPush(&head,8);
	Traverse(head);
	StackPop(&head);
	Traverse(head);
	StackPop(&head);
	Traverse(head);
	StackPop(&head);
	Traverse(head);
	StackPop(&head);
	Traverse(head);
	StackPop(&head);
	Traverse(head);
*/	
	
	printf("Listede %d adet d���m vard�r.\n",HowManyNodes(head));
	printf("Listede %d adet d���m vard�r.\n",HowManyNodesV2(head));
	
	
	AddLast(&head,20);
	Traverse(head);
	AddFront(&head,12);
	Traverse(head);
	AddFront(&head,5);
	Traverse(head);
	AddMiddle(&head,27);
	Traverse(head);
	AddFront(&head,33);
	Traverse(head);
	AddLast(&head,15);
	Traverse(head);
	AddFront(&head,24);
	Traverse(head);
	AddMiddle(&head,41);
	Traverse(head);
	AddLast(&head,1);
	Traverse(head);
	AddMiddle(&head,17);
	Traverse(head);
	AddFront(&head,7);
	Traverse(head);
	AddLast(&head,45);
	Traverse(head);
	
	printf("Listede %d adet d���m vard�r.\n",HowManyNodes(head));
	printf("Listede %d adet d���m vard�r.\n",HowManyNodesV2(head));
	
	
/*	tmp = SearchNode(head);
	
	if(tmp != NULL) {
		
		printf("%d listede bulunmaktad�r!!\n",tmp->data);
		
	} else {
		
		printf("�stenilen say� listede bulunmad�!!\n");
		
	}
	
	
	DeleteFirst(&head);
	Traverse(head);
	DeleteFirst(&head);
	Traverse(head);
	DeleteFirst(&head);
	Traverse(head);
	DeleteFirst(&head);
	Traverse(head);
	DeleteLast(&head);
	Traverse(head);
	DeleteMiddle(&head);
	Traverse(head);		
	DeleteMiddle(&head);
	Traverse(head);		
	
	tmp = SearchNode(head);
	
	if(tmp != NULL) {
		
		printf("%d listede bulunmaktad�r!!\n",tmp->data);
		
	} else {
		
		printf("�stenilen say� listede bulunmad�!!\n");
		
	}
	
*/	
	
return 0;	
}

NODE* CreateNode(int x) {
	
	NODE *newnode = (NODE*) malloc(sizeof(NODE));
	
	newnode->data = x;
	newnode->next = NULL;
	
}

NODE* SearchNode(NODE *root) {
	
	NODE *tmp;
	int sayi;
	
	printf("Listede aramak istedi�iniz say�\n");
	scanf("%d",&sayi);
	
	tmp = root;
	
	while((tmp != NULL) && (tmp->data != sayi)) {
	
		tmp = tmp->next;
	
	}
	
	return tmp;
	
}

void AddFront(NODE **root,int x) {
	
	NODE *newnode = CreateNode(x);
	
	newnode->next = *root;
	*root = newnode;
	
}

void AddLast(NODE **root,int x) {
	
	NODE *newnode=NULL;
	NODE *tmp=NULL;
	
	if(*root == NULL) {
		
		AddFront(root,x);
		
	} else {
		
		newnode = CreateNode(x);
		tmp = *root;
		
		while(tmp->next != NULL) {
			
			tmp = tmp->next;
			
		}
		
		newnode->next = tmp->next;
		tmp->next = newnode; 
		
	}
	
	
}

void AddMiddle(NODE **root,int x) {
	
	int sayi;
	NODE *newnode = NULL;
	NODE *tmp = NULL;
	
	printf("D���m� hangi say�n�n �n�ne eklemek istersin?\n");
	scanf("%d",&sayi);
	
	if(((*root)->data == sayi) || (*root == NULL)) {
		
		newnode = CreateNode(x);
		AddFront(root,x);
		
		
	} else {
		
		tmp = *root;
		
		while((tmp->next != NULL) && (tmp->next->data != sayi)) {
			
			tmp = tmp->next;
			
		}
		
		if(tmp->next != NULL) {
			
			newnode = CreateNode(x);
			newnode->next = tmp->next;
			tmp->next = newnode;
		
		} else {
			
			printf("�n�ne eklenmek istenen say� listede bulunmad��� i�in d���m eklenemedi!!\n");
			
		}
		
	}
	
	
}

void DeleteFirst(NODE **root) {
	
	NODE *tmp;
	
	tmp = *root;
	*root = (*root)->next;
	free(tmp);
	
}

void DeleteLast(NODE **root) {
	
	NODE *tmp;
	
	if((*root)->next == NULL) {
		
		DeleteFirst(root);
		printf("Listede eleman kalmad�!!\n");
		
	} else {
		
		tmp = *root;
		
		while(tmp->next->next != NULL) {
			
			tmp = tmp->next;
			
		}
		
		free(tmp->next);
		tmp->next = NULL;
	
	}
	
	
	
}

void DeleteMiddle(NODE **root) {
	
	int sayi;
	NODE *tmp;
	NODE *tmp2;
	
	printf("Listeden hangi say�y� silmek istersin?\n");
	scanf("%d",&sayi);
	
	if((*root)->data == sayi) {
		
		DeleteFirst(root);
		
	} else {
		
		tmp = *root;
		
		while((tmp->next != NULL) && (tmp->next->data != sayi)) {
			
			tmp = tmp->next;
			
		}
		
		if(tmp->next != NULL) {
		
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp2);
		
		} else {
			
			printf("%d listede bulunmad��� i�in silinemedi!!\n",sayi);
			
		}
		
	}
	
	
	
}

void StackPush(NODE **root,int x) {
	
	AddFront(root,x); 
	
}

void StackPop(NODE **root) {
	
	if(*root != NULL) {
	
		DeleteFirst(root);
		
		if((*root == NULL)) {
		
		printf("Stack Bo�ald�!!\n");
		
		}
		
	} else {
		
		printf("Stack Bo�!!\n");
		
	}
	
}

void Enqueue(NODE **root,int x) {
	
	if(*root == NULL) {
		
		AddFront(root,x);
		
	} else {
		
		AddLast(root,x);
		
	}
	
}

void Dequeue(NODE **root) {
	
	if(*root != NULL) {
		
		DeleteFirst(root);
		
		if(*root == NULL) {
			
			printf("Kuyruk bo�ald�!!");
			
		}
		
	} else {
		
		printf("Kuyruk bo�!!");
		
	}
	
}

int HowManyNodes(NODE *root) {
	
	NODE *tmp;
	int i;
	
	tmp = root;
	i = 0;
	
	while(tmp != NULL) {
	
		i++;
		tmp = tmp->next;
	
	}
	
	return i;
	
}

int HowManyNodesV2(NODE *root) {
	
	NODE *tmp;
	int i;
	
	i = 1;
	tmp = root;
	
	if(tmp == NULL) {
		
		return 0;
		
	} 
	
	return (i + HowManyNodes(tmp->next));
	
	
}

void Traverse(NODE *root) {
	
	NODE *tmp;
	
	tmp = root;
	
	while(tmp != NULL) {
		
		printf("%d ",tmp->data);
		tmp = tmp->next;
		
	}
	
	printf("\n");
	
}

