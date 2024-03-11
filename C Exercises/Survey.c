#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	
	int **survey;
	int **question;
	int i,j,y,n;
	
	survey = (int**) calloc(200,sizeof(int*));
	
	if(survey == NULL) {
		
		printf("Memory can not allocated!");
		return -1;
		
	} 
	
	for(i = 0; i < 200; i++) {
		
		survey[i] = (int*) calloc(30,sizeof(int));
		
		if(survey[i] == NULL) {
		
			printf("Memory can not allocated!");
			return -1;
		
		} 
		
	}
	
	question = (int**) calloc(2,sizeof(int));
	
	if(question == NULL) {
		
		printf("Memory can not allocated!");
		return -1;
		
	} 
	
	
	for(i = 0; i < 2; i++) {
		
		question[i] = (int*) calloc(30,sizeof(int));
		
		if(question[i] == NULL) {
		
			printf("Memory can not allocated!");
			return -1;
		
		} 
		
	}
	
	
	for(i = 0; i < 200; i++) {
		
		for(j = 0; j < 30; j++) {
			
			survey[i][j] = rand() % 2;
			
		}
	
	}
	
	
	for(i = 0; i < 30; i++) {
	
		y = n = 0;
				
		for(j = 0; j < 200; j++) {
			
			if(survey[i][j] == 1) {
				
				y++;
				
			} else {
				
				n++;
				
			}
			
		}
		
		question[0][i] = y;
		question[1][i] = n;
		
	}
	
	
	
	for(i = 0; i < 2; i++) {
		
		for(j = 0; j < 30; j++) {
			
			if((i == 0) && (j == 0)) {
				
				printf("Yes => ");
				
			}
			
			if((i == 1) && (j == 0)) {
				
				printf("No =>  ");
				
			}
			
			printf("%3.d ",question[i][j]);
		
		}
		
		printf("\n");
	
	}
	
	

	for(i = 0; i < 200; i++) {
		
		free(survey[i]);
		
	}
	
	free(survey);
	
	return 0;
}
