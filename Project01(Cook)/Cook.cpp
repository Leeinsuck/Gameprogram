#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

int menu_display(void);		  
int sub_menu_display01(void);
int sub_menu_display02(void); 
void sub_main01(void);       
void sub_main02(void);      
void press_any_key(void);     

void volume_calculation(void);
void weight_calculation(void);
void print_unit(char *ms_char[], int n);
void volume_calculate(int basic, int transe, double measure, char *ms_char[]);
void weight_calculate(int basic, int transe, double measure, char *ms_char[]);

void display_Cook1();	
void Cooking(int s1,int s2, int s3);
int select1(void);
int select2(void);
int select3(void);
int select1_display(void);
int select2_display(void);
int select3_display(void);


int success(void);
int failure(void);
int calc_frequency(int octave, int inx);  

int main(void)
{
	int c;
	while((c=menu_display())!=3)
	{
		switch(c)
		{
			case 1 : sub_main01();
				break;
			case 2 : sub_main02();
				break;
			default : break;
		}
	}
	printf("\n");
	return 0;
}
int menu_display(void)
{
    int select;
    system("cls");
    printf("디지털 레시피\n\n");
    printf("1. 요리하기 \n");
    printf("2. 단위환산 \n");
    printf("3. 프로그램 종료\n\n");
    printf("메뉴번호 입력>");
    select=getch()-48;
    return select;
}

void sub_main01(void)
{
    int c;
    while((c=sub_menu_display01())!=2)
    {
      switch(c)
      {
           case 1 : display_Cook1();
  	 	     break;
           default : break;
     }
   }
}

void sub_main02(void)
{
    int c;
    while((c=sub_menu_display02())!= 3)
    {
      switch(c)
      {
           case 1 : volume_calculation();
  	 	     break;
           case 2 : weight_calculation();
  		     break;
           default : break;
     }
   }
}
int sub_menu_display01(void)
{
    int select;
    system("cls");
    printf("요리\n\n");
    printf("1. 계란찜\n");
    printf("2. 메인 메뉴로 이동\n\n");
    printf("메뉴번호 입력>");
    select=getch()-48;
    return select;
}
int sub_menu_display02(void)
{
        int select;
        system("cls");
        printf("단위환산\n\n");
        printf("1. 부피(volume) 환산 \n");
        printf("2. 무게(weight) 환산 \n");
        printf("3. 메인 메뉴로 이동\n\n");
        printf("메뉴번호 입력>");
        select=getch()-48;
        return select;
}

void press_any_key(void)
{
       printf("\n\n");
       printf("아무키나 누르면 이전 메뉴로...");
       getch();
}

void volume_calculation(void)
{

  char *ms_char[6]={"밀리리터", "teaspoon", "tablespoon", "cup", "리터", "갤런"};
  double measure;
  int basic, transe;
  system("cls");	
  printf("부피에 대한 도량형 환산 프로그램\n\n");
  print_unit(ms_char, 6);
  printf("\n\n기본단위와 변환단위\n입력 후 Enter(예:1 5)>");
  scanf("%d %d",&basic,&transe);
  printf("값을 입력하고 Enter>");
  scanf("%lf", &measure);
  printf("\n");
  volume_calculate(basic, transe, measure, ms_char);
  press_any_key();
}

void weight_calculation(void)
{

  char *ms_char[4]={"그램", "온즈", "파운드", "킬로그램"};
  double measure;
  int basic, transe;
  system("cls");	
  printf("무게에 대한 도량형 환산 프로그램\n\n");
  print_unit(ms_char, 4);
  printf("\n\n기본단위와 변환단위\n입력 후 Enter(예:1 5)>");
  scanf("%d %d",&basic,&transe);

  printf("값을 입력하고 Enter>");
  scanf("%lf", &measure);
  printf("\n");
  weight_calculate(basic, transe, measure, ms_char);
  press_any_key();

}

void print_unit(char *ms_char[], int n)
{

	int i;
	for(i=0;i<n;i++)
	{
		printf("%d:%-9s  ", i, ms_char[i]);
		if (i%3==2)
			printf("\n");
	}
}

void volume_calculate(int basic, int transe, double measure, char *ms_char[])
{

  double msre[10], unit, result;
  msre[0]=3758.279;
  msre[1]=msre[0]/5.;
  msre[2]=msre[1]/3.;
  msre[3]=msre[2]/16.667;
  msre[4]=msre[3]/4.;
  msre[5]=msre[4]/3.758;
  unit=msre[basic];
  result=measure*(msre[transe]/unit);
  printf("%.3f %-10s : ", measure, ms_char[basic]);
  printf("%.3f %-10s", result, ms_char[transe]);
}
void weight_calculate(int basic, int transe, double measure, char *ms_char[])
{

  double msre[4], unit, result;
  msre[0]=1000;
  msre[1]=msre[0]/28.3459;
  msre[2]=msre[1]/16.;
  msre[3]=msre[2]/2.205;
  unit=msre[basic];
  result=measure*(msre[transe]/unit);
  printf("%.2f %-8s:", measure, ms_char[basic]);
  printf("%.5f %-8s", result, ms_char[transe]);
}

void display_Cook1(void)
{
	
	int s1,s2,s3;
	system("cls");
  	s1 = select1();
  	s2 = select2();
  	s3 = select3();
  	Cooking(s1,s2,s3);
  	if(s1==1&&s2==2&&s3==1){
  		success();
	  }else{
	  	failure();
	  }
	printf("\n요리끝.\n");
	press_any_key();
	
}

void Cooking(int s1, int s2, int s3){
	system("cls");
	if(s1 == 1){
		if(s2 == 1){
			if(s3 == 1){
				printf("계란찜이 짜게 요리 되었습니다.") ;
			}else if(s3 == 2){
			 	printf("계란찜이 달고 짜게 요리 되었습니다.");
			 }else{
			 	printf("계란찜이 맵고 짜게 요리 되었습니다.");
			 }
		}else if(s2 == 2){
			if(s3 == 1){
				printf("계란찜이 맛있게 요리 되었습니다.");
			 }else if(s3 == 2){
			 	printf("계란찜이 달게 요리 되었습니다."); 
			 }else{
			 	printf("계란찜이 맵게 요리 되었습니다."); 
			 }
		}else{
			if(s3 == 1){
				printf("계란찜이 시큼하고 짜게 요리 되었습니다."); 
			 }else if(s3 == 2){
			 	printf("계란찜이 시큼하고 달게 요리 되었습니다."); 
			 }else{
			 	printf("계란찜이 시큼하고 맵게 요리 되었습니다."); 
			 }
		}
	}else{
		printf("계란찜으로 요리가 안됩니다.");
	}	
}
	


int select1(void)
{
	int c;
	while((c=select1_display())!=4)
	{
		switch(c)
		{
			case 1 : return 1;
				break;
			case 2 : return 2;
				break;
			case 3 : return 3;
			default : break;
		}
	}
}
int select1_display(void)
{
    int select;
    system("cls");
    printf("재료 선택해주세요\n\n");
    printf("1. 계란 \n");
    printf("2. 대게 \n");
    printf("3. 닭고기 \n");
    printf("메뉴번호 입력>");
    select=getch()-48;
    return select;
}

int select2(void)
{
	int c;
	while((c=select2_display())!=4)
	{
		switch(c)
		{
			case 1 : return 1;
				break;
			case 2 : return 2;
				break;
			case 3 : return 3;
			default : break;
		}
	}
}
int select2_display(void)
{
    int select;
    system("cls");
    printf("재료 선택해주세요\n\n");
    printf("1. 간장 \n");
    printf("2. 물 \n");
    printf("3. 식초 \n");
    printf("메뉴번호 입력>");
    select=getch()-48;
    return select;
}

int select3(void)
{
	int c;
	while((c=select3_display())!=4)
	{
		switch(c)
		{
			case 1 : return 1;
				break;
			case 2 : return 2;
				break;
			case 3 : return 3;
			default : break;
		}
	}
}
int select3_display(void)
{
    int select;
    system("cls");
    printf("재료 선택해주세요\n\n");
    printf("1. 소금 \n");
    printf("2. 설탕 \n");
    printf("3. 고춧가루 \n");
    printf("메뉴번호 입력>");
    select=getch()-48;
    return select;
}

int success(void){
	int index[]={0, 2, 4, 5, 7, 9, 11, 12};
	int freq[8],code, i;
	int P1[3]={0,4,7};
	for(i=0;i<8;i++)
		freq[i]=calc_frequency(4, index[i]);
	for(i=0;i<=3;i++)
		Beep(freq[P1[i]],300);
	return 0;
}

int failure(void){
	int index[]={0, 2, 4, 5, 7, 9, 11, 12};
	int freq[8],code, i;
	int P1[1]={9};
	for(i=0;i<8;i++)
		freq[i]=calc_frequency(4, index[i]);
	for(i=0;i<=1;i++)
		Beep(freq[P1[i]],300);
	return 0;
}

int calc_frequency(int octave, int inx)
{
	double do_scale=32.7032;
	double ratio=pow(2., 1.0/12.), temp;
	int i;
	temp=do_scale*pow(2, octave-1);
	for(i=0;i<inx;i++)
	{
		temp=(int)(temp+0.5);
		temp*=ratio;
	}
	return (int) temp;
}
