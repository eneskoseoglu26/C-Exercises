#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define infinity 9999

int G[MAX][MAX],spanning[MAX][MAX],n;

int Prims();

int main() {
	
	int i,j,total_cost;
	
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter adjacency matrix\n");
	for(i = 0; i < n; i++) {
		
		for(j = 0; j < n; j++) {
			
			scanf("%d",&G[i][j]);
			
		}
		
	}
	
	total_cost = Prims();
	
	printf("Spanning tree matrix\n");
	for(i = 0; i < n; i++) {
		
		printf("\n");
		
		for(j = 0; j < n; j++) {
			
			printf("%d\t",spanning[i][j]);
			
		}
		
	}
	
	printf("\n\nTotal cost of spanning tree = %d",total_cost);
	return 0;	
	
}

int Prims() {
	
	int cost[MAX][MAX];
	int u,v,min_distance,distance[MAX],from[MAX];
	int visited[MAX],edges,i,j,min_cost;
	
	for(i = 0; i < n; i++) {
		
		for(j = 0; j < n; j++) {
			
			if(G[i][j] == 0) {
				
				cost[i][j] = infinity;
				
			} else {
				
				cost[i][j] = G[i][j];
				
			}
			
			spanning[i][j] = 0;
			
		}
		
	}
	
	distance[0] = 0;
	visited[0] = 1;
	
	for(i = 1; i < n; i++) {
		
		distance[i] = cost[0][i];
		from[i] = 0;
		visited[i] = 0;
				
	}
	
	min_cost = 0;
	edges = n - 1;
	
	while(edges > 0) {
		
		min_distance = infinity;
		
		for(i = 1; i < n; i++) {
		
			if((visited[i] == 0) && (distance[i] < min_distance)) {
				
				v = i;
				min_distance = distance[i];
				
			}	
			
		}
		
		u = from[v];
		spanning[u][v] = distance[v];
		spanning[v][u] = distance[v];
		edges--;
		visited[v] = 1;
		
		for(i = 1; i < n; i++) {
			
			if((visited[i] == 0) && (cost[i][v] < distance[i])) {
			
				distance[i] = cost[i][v];
				from[i] = v;
			
			}
				
		}
		
		min_cost += cost[u][v];
		
	}
	
	return min_cost;
	
}
