#define _CRT_SECURE_NO_WARNINGS    
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char w[255];              
    int l;                  
    bool b = true;    

    printf("단어를 입력하세요: ");
    scanf("%s", w);

    l = strlen(w);
    
    for (int i = 0; i < l / 2; i++)
    {
        if (w[i] != w[l - 1 - i])
        {
            b = false;
            break;
        }
    }
    if(b == 1){
    	printf("회문입니다.");
	}else{
		printf("회문이 아닙니다.");
	} 

    

    return 0;
}
