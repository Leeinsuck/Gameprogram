#define _CRT_SECURE_NO_WARNINGS    
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char w[255];              
    int l;                  
    bool b = true;    

    printf("�ܾ �Է��ϼ���: ");
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
    	printf("ȸ���Դϴ�.");
	}else{
		printf("ȸ���� �ƴմϴ�.");
	} 

    

    return 0;
}
