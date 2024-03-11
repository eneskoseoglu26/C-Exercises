#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct edge {
	
	int u,v,w;
	
}EDGE;

typedef struct edgelist {

	EDGE data[MAX];
	int n;

}LIST;

LIST  elist;
LIST spanlist;
int G[MAX][MAX],n;

void Kruskal();
int Find(int belongs[],int vertexno);
void Union(int belongs[], int c1,int c2);
void Sort();
void Print();

int main() {

	int i,j,total_cost;
	
	printf("Enter the number of vertices\n");
	scanf("%d",&n);

	printf("Enter the adjancecy matrix\n");
	
	for(i = 0; i < n; i++) {
		
		for(j = 0; j < n; j++) {
			
			scanf("%d",&G[i][j]);
			
		}
		
	}	
	
	Kruskal();
	Print();
	

return 0;	
}

void Kruskal() {

	int belongs[MAX],i,j,cno1,cno2;
	
	elist.n = 0;
	
	for(i = 1; i < n; i++) {
		
		for(j = 0; j < i; j++) {
			
			if(G[i][j] != 0) {
				
				elist.data[elist.n].u = i;
				elist.data[elist.n].v = j;
				elist.data[elist.n].w = G[i][j];
				elist.n++;
				
			}
			
		}
		
	}

	Sort();
	
	for(i = 0; i < n; i++) {
		
		belongs[i] = i;
		
	}	
	
	spanlist.n = 0;
	i = 0;
	
	while((i < elist.n) && (spanlist.n < n)) {
		
		cno1 = Find(belongs,elist.data[i].u);
		cno2 = Find(belongs,elist.data[i].v);
		
		if(cno1 != cno2) {
			
			spanlist.data[spanlist.n] = elist.data[i];
			spanlist.n++;
			Union(belongs,cno1,cno2);
					
		}
			
		i++;	
			
	}
	
}

void Union(int belongs[], int c1, int c2) {
	
	int i; 
	
	for(i = 0; i < n; i++) {
		
		if(belongs[i] == c2) {
			
			belongs[i] = c1;
			
		}
		
	}
	
}	

int Find(int belongs[],int vertexno) {
	
	return(belongs[vertexno]);
	
}

void Sort() {
	
	int i,j;
	
	EDGE temp;
	
	for(i=1;i<elist.n;i++) {
	
		for(j=0;j<elist.n-1;j++)
	
			if(elist.data[j].w>elist.data[j+1].w) {
			
				temp=elist.data[j];
				elist.data[j]=elist.data[j+1];
				elist.data[j+1]=temp;
				
			}

	}
	
}

void Print() {
	
	int i,cost=0;
	
	for(i = 0; i < spanlist.n;i++) {
		
		printf("%d %d %d\n",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
		cost += spanlist.data[i].w;
		
	}
	
	printf("Cost of MST = %d",cost);
	
}

