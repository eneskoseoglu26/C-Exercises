#include <stdio.h>
#define N 30

int LengthOfString(char w[], int i) {
	
	if(w[i] == '\0') {
		
		return i;
		
	} else {
		
		i++;
		LengthOfString(w,i);
		
	}
	
}

int LengthOfString2(char *w) {
	
	if(*w == '\0') {
		
		return 0;
		
	} 
	
	return (1 + LengthOfString2(++w));
	
}


int main() {

	char word[N] = "";	
	int length;
	int i=0;
	
	//length = LengthOfString(word,i);
	length = LengthOfString2(word);
	printf("%s = %d\n",word,length);
	
	return 0;
}
