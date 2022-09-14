#include <stdio.h>

int main(){
	char string[20];
	char c;
	while(1){
		if(c =='\n'){
			break;
		}
		scanf("%c",&c);
		printf("%c",c);
	}
	printf("Good Bye\n");

	
	return 0;
}
