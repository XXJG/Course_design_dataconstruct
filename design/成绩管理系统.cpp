#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*------------ѧ���ṹ������------------------ */
typedef struct student{
char no[10];
char name[16];
float score;
}STU;
STU students[100];


/*    ----------������������------------------*/
int Num();                                                   //��ȡѧ������
STU *input(int length);                              //����ѧ����Ϣ
void output(STU *pa,int length);                         //���ѧ����Ϣ
void dele(STU *pa,int length);                        //ɾ��ѧ����Ϣ
void search(STU *pa,int length);                         //����ѧ����Ϣ
void Add(STU *pa,int length);                         //����ѧ����Ϣ
void classfly(STU *pa,int length);             //���ճɼ���ѧ�����з���
void scorelist(STU *pa,int length);  //ѧ����Ϣ���ճɼ���������
void IO_Read();   //              ��ȡѧ����Ϣ
void IO_Write(int length);                    //��ѧ����Ϣд���ļ� 

/*                  ����������               */
int main()                              
{
	int flag;
    int num; 
    struct student *pa = NULL;  
    struct student *p = NULL;  
    printf("*************************��ӭʹ��ѧ���ɼ�����ϵͳ*******************************\n\n");  
    printf("�밴���������ѧ������ϵͳ:\n");  
    getchar();  
    system("cls");  
    printf("================================================================================\n");  
    printf("------------------------ ��ѡ��Ҫ���������-----------------------------------\n");  
    printf("-------------------------- 1 ����ѧ����Ϣ---------------------------------------\n");  
    printf("-------------------------- 2 ���ѧ����Ϣ---------------------------------------\n");  
    printf("-------------------------- 3 ɾ��ѧ����Ϣ---------------------------------------\n");  
    printf("-------------------------- 4 ����ѧ����Ϣ---------------------------------------\n");  
    printf("-------------------------- 5 ����ѧ����Ϣ---------------------------------------\n");  
    printf("-------------------------- 6 ѧ����Ϣ���շ�������-------------------------------\n");  
    printf("-------------------------- 7 ���ļ��ж�ȡѧ����Ϣ-------------------------------\n");  
    printf("-------------------------- 8 ��ѧ���ĳɼ����Ӵ�С���� ------------------------\n");  
    printf("-------------------------- 9 ��ѧ����Ϣ���浽�ļ���-----------------------------\n");  
    printf("-------------------------- 10 �˳�       ---------------------------------------\n");  
    printf("================================================================================\n");  
	while(1)
	{
	printf("��������еĲ���\n");
	scanf("%d",&flag);
	switch(flag)
	{	case 1:{       //����ѧ����Ϣ
	system("cls"); 
	num=Num();
    p=input(num);
	}break;
	case 2:{          //���ѧ����Ϣ
		    system("cls");  
            output(p,num);  
		   }break;
	case 3:{           //ɾ��ѧ����Ϣ
		    system("cls");  
            dele(p,num);  
		   }break;
	case 4:{            //����ѧ����Ϣ
		   system("cls");  
            search(p,num);
		   }break;
	case 5:{          //����ѧ����Ϣ
		    system("cls");  
            Add(p, num);  
		   }break;
	case 6:{             //ѧ����Ϣ���շ�������
		    system("cls");  
            classfly(p,num);
		   }break;
	case 7:{            //���ļ��ж�ȡѧ����Ϣ
		   system("cls"); 
		   IO_Read();
		   }break;
	case 8:{           //��ѧ���ĳɼ����Ӵ�С����
		   system("cls");
           scorelist(p,num);
		   }break;
	case 9:{    //��ѧ����Ϣ���浽�ļ���
		num=Num();
		   system("cls");
           IO_Write(num); 
		   }break;
	case 10:{
			exit(0);  
			}break;
	}
	}
return 0;
}

/*   ---------- �ֺ�������  -------------------       */

int Num()                                                    //��ȡѧ������
{
	int num;
printf("������ѧ������\n");
scanf("%d",&num);
return num;
}

STU *input(int length)                              //����ѧ����Ϣ
{
	STU *pa;
pa=(struct student *)malloc(sizeof(struct student));
int i;
for(i=0;i<length;i++)
{
 printf("�������%d��ѧ��������:\n", i+1);
 scanf("%s",pa[i].name);
 printf("�������%d��ѧ����ѧ��:\n",i+1);
 scanf("%s",pa[i].no);
 printf("�������%d��ѧ���ĳɼ�:\n", i+1);
 scanf("%f",&pa[i].score);
}
return pa;
}

void output(STU *pa,int length)                         //���ѧ����Ϣ
{
	int i;
printf("ѧ��\t����\t����\n");
for(i=0;i<length;i++)
printf("%s %s %f",pa[i].name,pa[i].no,pa[i].score);
}

void dele(STU *pa,int length)                        //ɾ��ѧ����Ϣ
{
	int i,flag,j,n;
	char name1[10];
	 char no1[10];
printf("��ѡ������ѧ��ɾ��������������ɾ��:(1 or 2)\n");
scanf("%d",&flag);
if(flag==1)
{
printf("������ѧ�ţ�\n");
scanf("%s",no1);
for (i=0; i<length;i++)  
for(j=0;j<10;j++)
        if (no1[j]==pa[i].no[j])    
            n=i;  
    for (i =n;i<length;i++)  
        pa[i-1] = pa[i];  
    output(pa,length-1);
}
else if(flag==2)
{
printf("������������\n");
scanf("%s",name1);
for (i=0; i<length;i++)  
        if (0 ==strcmp(pa[i].name, name1))    
            n=i;  
    for (i =n;i<length;i++)  
      
        pa[i-1]= pa[i];  
   
    output(pa,length-1);
}
}

void search(STU *pa,int length)                         //����ѧ����Ϣ
{
	int i,flag,j,n;
	char name2[10];
	char no2[10];
printf("��ѡ������ѧ�Ų��һ���������������:(1 or 2)\n");
scanf("%d",&flag);
if(flag==1)
{
printf("������ѧ�ţ�\n");
scanf("%s",no2);
for (i=0; i<length;i++)  
for(j=0;j<10;j++)
        if (no2[j]==pa[i].no[j])    
            n=i;  
    output(&pa[n],1);
}
else if(flag==2)
{
printf("������������\n");
scanf("%s",name2);
for (i=0; i<length;i++)  
        if (0 ==strcmp(pa[i].name, name2))    
            n=i;  
    output(&pa[n],1);
}
}

void Add(STU *pa,int length)                         //����ѧ����Ϣ
{
  int n,i; 
    printf("��������ӵ�ѧ��������:\n");  
    scanf("%d", &n);  
    struct student *p = NULL;    
    p = (struct student *)malloc(sizeof(struct student));  
    for (i=0;i<n; i++)  
    {  
        printf("�������%d��ѧ��������:\n", i + 1); 
        scanf("%s", p[i].name);  
        printf("�������%d��ѧ����ѧ��:\n", i + 1);
        scanf("%s", p[i].no);  
        printf("�������%d��ѧ���ĳɼ�:\n", i + 1);
        scanf("%f",&p[i].score);  
    }  
    output(pa,length);//���ѧ����Ϣ  
    output(p,n);//���ѧ����Ϣ  
}

void classfly(STU *pa,int length)             //���ճɼ���ѧ�����з���
{
int i;
for(i=0;i<length;i++)
{
if(pa[i].score>=90) printf("%s---------A\n",pa[i].name); 
if(pa[i].score<90&&pa[i].score>=80) printf("%s---------B\n",pa[i].name); 
if(pa[i].score<80&&pa[i].score>=70) printf("%s---------C\n",pa[i].name); 
if(pa[i].score<70&&pa[i].score>=60) printf("%s---------D\n",pa[i].name); 
if(pa[i].score<60) printf("%s---------E\n",pa[i].name); 
}
}

void scorelist(STU *pa,int length)  //ѧ����Ϣ���ճɼ���������
{  
   STU t;
    for (int i=0;i<length-1;i++)//ð������  
    {  
        for (int j=0;j<length-i;j++)  
        {  
            if (pa[j].score<pa[j+1].score)//�Գɼ��Ӵ�С����  
            {  
                t= pa[j];  
                pa[j] = pa[j + 1];  
                pa[j+1] =t;  
            }  
        }  
    }  
  
    output(pa, length);
}  

void IO_Read()   //             ���ļ���ȡѧ����Ϣ
{ 
     FILE *fp;  
     int i;  
     if ((fp=fopen("C:\\nfo.txt","rb"))==NULL)  
     {  
         printf("���ܴ��ļ�!\n");  
         return;  
     }  
	 for(i=0;fread(&students[i],sizeof(struct  student),1,fp)==1;i++)
  
     printf("%s %s %f\n",students[i].name,students[i].no,students[i].score); 
		
     fclose(fp);  
}  
  
   
void IO_Write(int length)                    //��ѧ����Ϣд���ļ� 
{  
     FILE *fp;  
     int i; 
	 STU *stud;
     if ((fp=fopen("C:\\nfo.txt","wb"))==NULL)    
     {  
         printf("���ܴ��ļ�!\n");  
         return;  
     }  
       stud=input(length);
         for ( i =0; i < length; i++)  
        if (fwrite(stud, sizeof(struct student),1,fp)!=1)  
            printf("file write error!\n");        
     fclose(fp);  
}  