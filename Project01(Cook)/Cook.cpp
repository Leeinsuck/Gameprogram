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
    printf("������ ������\n\n");
    printf("1. �丮�ϱ� \n");
    printf("2. ����ȯ�� \n");
    printf("3. ���α׷� ����\n\n");
    printf("�޴���ȣ �Է�>");
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
    printf("�丮\n\n");
    printf("1. �����\n");
    printf("2. ���� �޴��� �̵�\n\n");
    printf("�޴���ȣ �Է�>");
    select=getch()-48;
    return select;
}
int sub_menu_display02(void)
{
        int select;
        system("cls");
        printf("����ȯ��\n\n");
        printf("1. ����(volume) ȯ�� \n");
        printf("2. ����(weight) ȯ�� \n");
        printf("3. ���� �޴��� �̵�\n\n");
        printf("�޴���ȣ �Է�>");
        select=getch()-48;
        return select;
}

void press_any_key(void)
{
       printf("\n\n");
       printf("�ƹ�Ű�� ������ ���� �޴���...");
       getch();
}

void volume_calculation(void)
{

  char *ms_char[6]={"�и�����", "teaspoon", "tablespoon", "cup", "����", "����"};
  double measure;
  int basic, transe;
  system("cls");	
  printf("���ǿ� ���� ������ ȯ�� ���α׷�\n\n");
  print_unit(ms_char, 6);
  printf("\n\n�⺻������ ��ȯ����\n�Է� �� Enter(��:1 5)>");
  scanf("%d %d",&basic,&transe);
  printf("���� �Է��ϰ� Enter>");
  scanf("%lf", &measure);
  printf("\n");
  volume_calculate(basic, transe, measure, ms_char);
  press_any_key();
}

void weight_calculation(void)
{

  char *ms_char[4]={"�׷�", "����", "�Ŀ��", "ų�α׷�"};
  double measure;
  int basic, transe;
  system("cls");	
  printf("���Կ� ���� ������ ȯ�� ���α׷�\n\n");
  print_unit(ms_char, 4);
  printf("\n\n�⺻������ ��ȯ����\n�Է� �� Enter(��:1 5)>");
  scanf("%d %d",&basic,&transe);

  printf("���� �Է��ϰ� Enter>");
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
	printf("\n�丮��.\n");
	press_any_key();
	
}

void Cooking(int s1, int s2, int s3){
	system("cls");
	if(s1 == 1){
		if(s2 == 1){
			if(s3 == 1){
				printf("������� ¥�� �丮 �Ǿ����ϴ�.") ;
			}else if(s3 == 2){
			 	printf("������� �ް� ¥�� �丮 �Ǿ����ϴ�.");
			 }else{
			 	printf("������� �ʰ� ¥�� �丮 �Ǿ����ϴ�.");
			 }
		}else if(s2 == 2){
			if(s3 == 1){
				printf("������� ���ְ� �丮 �Ǿ����ϴ�.");
			 }else if(s3 == 2){
			 	printf("������� �ް� �丮 �Ǿ����ϴ�."); 
			 }else{
			 	printf("������� �ʰ� �丮 �Ǿ����ϴ�."); 
			 }
		}else{
			if(s3 == 1){
				printf("������� ��ŭ�ϰ� ¥�� �丮 �Ǿ����ϴ�."); 
			 }else if(s3 == 2){
			 	printf("������� ��ŭ�ϰ� �ް� �丮 �Ǿ����ϴ�."); 
			 }else{
			 	printf("������� ��ŭ�ϰ� �ʰ� �丮 �Ǿ����ϴ�."); 
			 }
		}
	}else{
		printf("��������� �丮�� �ȵ˴ϴ�.");
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
    printf("��� �������ּ���\n\n");
    printf("1. ��� \n");
    printf("2. ��� \n");
    printf("3. �߰�� \n");
    printf("�޴���ȣ �Է�>");
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
    printf("��� �������ּ���\n\n");
    printf("1. ���� \n");
    printf("2. �� \n");
    printf("3. ���� \n");
    printf("�޴���ȣ �Է�>");
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
    printf("��� �������ּ���\n\n");
    printf("1. �ұ� \n");
    printf("2. ���� \n");
    printf("3. ���尡�� \n");
    printf("�޴���ȣ �Է�>");
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
