#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*------------学生结构体类型------------------ */
typedef struct student{
char no[10];
char name[16];
float score;
}STU;
STU students[100];


/*    ----------函数声明部分------------------*/
int Num();                                                   //获取学生人数
STU *input(int length);                              //输入学生信息
void output(STU *pa,int length);                         //输出学生信息
void dele(STU *pa,int length);                        //删除学生信息
void search(STU *pa,int length);                         //查找学生信息
void Add(STU *pa,int length);                         //增加学生信息
void classfly(STU *pa,int length);             //按照成绩对学生进行分类
void scorelist(STU *pa,int length);  //学生信息按照成绩进行排序
void IO_Read();   //              读取学生信息
void IO_Write(int length);                    //将学生信息写入文件 

/*                  主函数部分               */
int main()                              
{
	int flag;
    int num; 
    struct student *pa = NULL;  
    struct student *p = NULL;  
    printf("*************************欢迎使用学生成绩管理系统*******************************\n\n");  
    printf("请按任意键进入学生管理系统:\n");  
    getchar();  
    system("cls");  
    printf("================================================================================\n");  
    printf("------------------------ 请选择要操作的命令：-----------------------------------\n");  
    printf("-------------------------- 1 输入学生信息---------------------------------------\n");  
    printf("-------------------------- 2 输出学生信息---------------------------------------\n");  
    printf("-------------------------- 3 删除学生信息---------------------------------------\n");  
    printf("-------------------------- 4 查找学生信息---------------------------------------\n");  
    printf("-------------------------- 5 增加学生信息---------------------------------------\n");  
    printf("-------------------------- 6 学生信息按照分数分类-------------------------------\n");  
    printf("-------------------------- 7 从文件中读取学生信息-------------------------------\n");  
    printf("-------------------------- 8 将学生的成绩按从大到小排序 ------------------------\n");  
    printf("-------------------------- 9 将学生信息保存到文件中-----------------------------\n");  
    printf("-------------------------- 10 退出       ---------------------------------------\n");  
    printf("================================================================================\n");  
	while(1)
	{
	printf("请输入进行的操作\n");
	scanf("%d",&flag);
	switch(flag)
	{	case 1:{       //输入学生信息
	system("cls"); 
	num=Num();
    p=input(num);
	}break;
	case 2:{          //输出学生信息
		    system("cls");  
            output(p,num);  
		   }break;
	case 3:{           //删除学生信息
		    system("cls");  
            dele(p,num);  
		   }break;
	case 4:{            //查找学生信息
		   system("cls");  
            search(p,num);
		   }break;
	case 5:{          //增加学生信息
		    system("cls");  
            Add(p, num);  
		   }break;
	case 6:{             //学生信息按照分数分类
		    system("cls");  
            classfly(p,num);
		   }break;
	case 7:{            //从文件中读取学生信息
		   system("cls"); 
		   IO_Read();
		   }break;
	case 8:{           //将学生的成绩按从大到小排序
		   system("cls");
           scorelist(p,num);
		   }break;
	case 9:{    //将学生信息保存到文件中
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

/*   ---------- 分函数部分  -------------------       */

int Num()                                                    //获取学生人数
{
	int num;
printf("请输入学生人数\n");
scanf("%d",&num);
return num;
}

STU *input(int length)                              //输入学生信息
{
	STU *pa;
pa=(struct student *)malloc(sizeof(struct student));
int i;
for(i=0;i<length;i++)
{
 printf("请输入第%d个学生的姓名:\n", i+1);
 scanf("%s",pa[i].name);
 printf("请输入第%d个学生的学号:\n",i+1);
 scanf("%s",pa[i].no);
 printf("请输入第%d个学生的成绩:\n", i+1);
 scanf("%f",&pa[i].score);
}
return pa;
}

void output(STU *pa,int length)                         //输出学生信息
{
	int i;
printf("学号\t姓名\t分数\n");
for(i=0;i<length;i++)
printf("%s %s %f",pa[i].name,pa[i].no,pa[i].score);
}

void dele(STU *pa,int length)                        //删除学生信息
{
	int i,flag,j,n;
	char name1[10];
	 char no1[10];
printf("请选择输入学号删除还是输入姓名删除:(1 or 2)\n");
scanf("%d",&flag);
if(flag==1)
{
printf("请输入学号：\n");
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
printf("请输入姓名：\n");
scanf("%s",name1);
for (i=0; i<length;i++)  
        if (0 ==strcmp(pa[i].name, name1))    
            n=i;  
    for (i =n;i<length;i++)  
      
        pa[i-1]= pa[i];  
   
    output(pa,length-1);
}
}

void search(STU *pa,int length)                         //查找学生信息
{
	int i,flag,j,n;
	char name2[10];
	char no2[10];
printf("请选择输入学号查找还是输入姓名查找:(1 or 2)\n");
scanf("%d",&flag);
if(flag==1)
{
printf("请输入学号：\n");
scanf("%s",no2);
for (i=0; i<length;i++)  
for(j=0;j<10;j++)
        if (no2[j]==pa[i].no[j])    
            n=i;  
    output(&pa[n],1);
}
else if(flag==2)
{
printf("请输入姓名：\n");
scanf("%s",name2);
for (i=0; i<length;i++)  
        if (0 ==strcmp(pa[i].name, name2))    
            n=i;  
    output(&pa[n],1);
}
}

void Add(STU *pa,int length)                         //增加学生信息
{
  int n,i; 
    printf("请输入添加的学生的人数:\n");  
    scanf("%d", &n);  
    struct student *p = NULL;    
    p = (struct student *)malloc(sizeof(struct student));  
    for (i=0;i<n; i++)  
    {  
        printf("请输入第%d个学生的姓名:\n", i + 1); 
        scanf("%s", p[i].name);  
        printf("请输入第%d个学生的学号:\n", i + 1);
        scanf("%s", p[i].no);  
        printf("请输入第%d个学生的成绩:\n", i + 1);
        scanf("%f",&p[i].score);  
    }  
    output(pa,length);//输出学生信息  
    output(p,n);//输出学生信息  
}

void classfly(STU *pa,int length)             //按照成绩对学生进行分类
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

void scorelist(STU *pa,int length)  //学生信息按照成绩进行排序
{  
   STU t;
    for (int i=0;i<length-1;i++)//冒泡排序  
    {  
        for (int j=0;j<length-i;j++)  
        {  
            if (pa[j].score<pa[j+1].score)//对成绩从大到小排序  
            {  
                t= pa[j];  
                pa[j] = pa[j + 1];  
                pa[j+1] =t;  
            }  
        }  
    }  
  
    output(pa, length);
}  

void IO_Read()   //             从文件读取学生信息
{ 
     FILE *fp;  
     int i;  
     if ((fp=fopen("C:\\nfo.txt","rb"))==NULL)  
     {  
         printf("不能打开文件!\n");  
         return;  
     }  
	 for(i=0;fread(&students[i],sizeof(struct  student),1,fp)==1;i++)
  
     printf("%s %s %f\n",students[i].name,students[i].no,students[i].score); 
		
     fclose(fp);  
}  
  
   
void IO_Write(int length)                    //将学生信息写入文件 
{  
     FILE *fp;  
     int i; 
	 STU *stud;
     if ((fp=fopen("C:\\nfo.txt","wb"))==NULL)    
     {  
         printf("不能打开文件!\n");  
         return;  
     }  
       stud=input(length);
         for ( i =0; i < length; i++)  
        if (fwrite(stud, sizeof(struct student),1,fp)!=1)  
            printf("file write error!\n");        
     fclose(fp);  
}  