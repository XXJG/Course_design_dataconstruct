#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>

/*----------------����������---------------*/
typedef struct biginteger
{
	char *num;                //ָ���������飨���0�б��������λ�� 
	char character;               //���ţ�1��ʾ������-1��ʾ������ 
	int digit;                 //���������λ����ʵ��λ���� 
}BigInteger,*pb; 

/*------------������������---------------------*/

void Trans(pb data1);
void Trim(pb data1); 
void BPrint(pb result);
int Equal(pb data1,pb data2);
void Add(pb data1,pb data2,pb result);
void Add1(pb data1,pb data2,pb result);
void Sub(pb data1,pb data2,pb result);
void Sub1(pb data1,pb data2,pb result);
void Multiply(pb data1,pb data2,pb result);
void Div(pb data1,pb data2);

/*--------------����������------------------*/

int main()
 {
 	BigInteger data1,data2,result;              //�����������1,2����������� 
	 int i=0,len;
     int flage;
     printf("\n==================================������������ =================================\n"); 
	 printf("�����������λ����");
	 scanf("%d",&len);
	 data1.num=(char *)malloc(sizeof(char) * (len+1));
     data1.digit=len +1;
	 data2.num=(char *)malloc(sizeof(char) * (len+1));
     data2.digit=len+1;
	 result.num=(char *)malloc(sizeof(char) * (2*len+1));
	 result.digit=2*len+1;

	 for(i=0;i<result.digit;i++)            
	 	result.num[i]=0;
	 printf("�������һ����:\t");
     scanf("%s",data1.num); 
	 printf("������ڶ�����:\t");
	 scanf("%s",data2.num);
	 Trans(&data1);
     Trans(&data2);
	printf("1.�ӷ� 2.���� 3.�˷� 4.���� 0.�˳�\n"); 
	printf("���1~4��ѡ��:");
	fflush(stdin);            //��ջ��漯 
	scanf("%d",&flage);
	switch(flage)
	{
		case 1:
			Add(&data1,&data2,&result);     
			break;
		case 2:
			Sub(&data1,&data2,&result);      
			break;
		case 3:
			Multiply(&data1,&data2,&result);     
			break; 
		case 4:
			if(data2.digit==1 && data2.num[0]==0)       
				printf("��������Ϊ0��\n");
			else
				Div(&data1,&data2);    
			break; 
		case 0:exit(0);
	}
	if(flage==1||flage==2||flage==3)
	{	printf("�����");
		BPrint(&result); 
		printf("\n");
	}

	return 0;
 }

/*----------------�ֺ�������-------------------*/

void Trans(pb data1)    //���ַ���תΪ���ֱ�ʾ 
{
	char *temp;                   
	int i,k,len;
	len=strlen(data1->num);        
    temp = (char *)malloc(sizeof(char)* len);
	i=0;
	data1->character=1;                 
	if(data1->num[0]=='-')          
	{
		data1->character=-1;
		i++;
	}
	k=0;                            
	while(data1->num[i]!='\0')       
	{
		if(data1->num[i]>='0' && data1->num[i] <='9')     //����Ϊ0~9 
		{
			temp[k]=data1->num[i]-'0';                 
			k++; 
		} 
		i++;
	}     
	
	for(i=0;i<data1->digit;i++)     
		data1->num[i]=0;
	data1->digit=k;                     
	for(i=0,k--;k>=0;k--,i++)          //����ʱ�����λ�÷��ñ��浽����num�� 
		data1->num[i]=temp[k];
	Trim(data1);                   
}

void Trim(pb data1)           //�����������ȥ��ǰ������0 
{
	int i;
	for(i=data1->digit-1;i>=0;i--)      
	{
		if(data1->num[i] !=0)              
		break;                      
	}
	if(i<0)                        
	{
		data1->digit=1;                     
		data1->num[0]=0;
	}else
	data1->digit=i+1;                 
} 

void BPrint(pb result)      //��������� 
{
	int j;
	if(result->character ==-1)            
		printf("-");                 
		if(result->digit ==1 &&result->num[0]==0)      
			printf("0");
		else                         
		{
			for(j=result->digit-1;j>=0;j--)             
				printf("%d",result->num[j]);
		} 
} 

int Equal(pb data1,pb data2)         //�ȽϾ���ֵ��С 
{
	int i;
	if(data1->digit>data2->digit)               
		return 1;
	else if(data1->digit<data2->digit)          
		return -1;
		else                              
		{
			i=data1->digit-1;                 
			while(i>=0)                       
			{
				if(data1->num[i]>data2->num[i])        
					return 1;
				else if(data1->num[i]<data2->num[i])      
					return -1;
				else                         
					i--;
			}
		}
		return 0;                             
} 

void Add(pb data1,pb data2,pb result)    // �ӷ����������ǲ�ִ�о���ļӷ��㷨
{
	int i;
	i=Equal(data1,data2);            
	if(i<0)                              
	{
		pb temp;
		temp=data1;                     
		data1=data2;
		data2=temp;
	}
	if(data1->character * data2->character <0)     //ͬ��ִ�мӷ�����ŵ��ü�������     
	{
		if(i==0)                            
		{
			result->digit =1;                 
			result->num[0]=0;              
			result->character =1;              
			return;                            
		}
		Sub1(data1,data2,result);         
	}else
Add1(data1,data2,result);               
} 

void Add1(pb data1,pb data2,pb result)     //�ӷ��㷨  
{
	int i,carry;
	carry=0;                            
	result->character =data1->character;           
	for(i=0;i<data1->digit;i++)             
		result->num[i]=data1->num[i];
	for(i=0;i<data2->digit;i++)               
	{
		result->num[i]=result->num[i]+data2->num[i]+carry;    
		carry=result->num[i]/10;       
		result->num[i]=result->num[i]%10;    
	}
	if(carry)                       
		result->num[i]=result->num[i]+carry;
Trim(result);                
} 

void Sub(pb data1,pb data2,pb result)     //��ż�����ִ�мӷ� 
{
	data2->character =-1 * data2 ->character;       
	Add(data1,data2,result);          
} 

void Sub1(pb data1,pb data2,pb result)     //ͬ���������
{
	int i,borrow;
	result->character =data1->character;         //������� 
	borrow=0;
	for(i=0;i<data1->digit;i++)                 
		result->num[i]=data1->num[i];
	for(i=0;i<=data2->digit;i++)
	{
		result->num[i]=result->num[i]-data2->num[i]-borrow;
		                                     
		if(result ->num[i]<0)             
		{
			result->num[i]=10+result->num[i];    
			borrow=1;                   
		}else
			borrow=0;
	}
	if(borrow==1)
		result->num[i]=result->num[i]-borrow;
	i=data1->digit;
	while(i>0)
	{
		if(result->num[i]==0)
			i--;
		else
			break;
	} 
	result->digit=i+1;               
    Trim(result);              
} 



void Multiply(pb data1,pb data2,pb result)    //�˷�����  
{
	char carry,temp;//��λ��
	int i,j,pos;//λ��
	for(i=0;i<data1->digit+data2->digit;i++)     
		result->num[i]=0;
	for(i=0;i<data2->digit;i++)               
	{
		carry=0;                               
		for(j=0;j<data1->digit;j++)                  
		{
			temp=data2->num[i] * data1->num[j]+carry;    
			carry =temp/10;                        
			temp=temp%10;                         
			pos=i+j;
			result->num[pos]+=temp;             
			carry=carry+result->num[pos]/10;       
			result->num[pos]=result->num[pos]%10; 
		}
		if(carry>0)
		{
			result->num[i+j]=carry;               
			result->digit=i+j+1;              
		}else
			result->digit=i+j;               
	} 
	result->character=data1->character * data2->character;       
} 


void Div(pb data1,pb data2)                              //�������� 
{
    pb result,residue;
	int i,j,k,m;               //k�������̽����m�����̵�λ�� ִ�м���
	char t;
	result=(pb)malloc(sizeof(BigInteger));
    residue=(pb)malloc(sizeof(BigInteger));
	result->character = data1->character * data2->character;        //�̵ķ��� 
	for(i=0;i<residue->digit;i++)            //������ȫ����0 
		residue->num[i]=0;
	m=0;
	for(i=data1->digit-1;i>=0;i--)
	{
		residue->digit=data2->digit+1;       
		for(j=data2->digit-1;j>0;j--)              
		residue->num[j]=residue->num[j-1];
    	residue->num[0]=data1->num[i];          
	 Trim(residue);                  
		k=0;   //���� 
		while(Equal(residue,data2)>=0)      
		{
		Sub1(residue,data2,residue);     
			k++;                       //���̼�1 
		} 
		result->num[m++]=k;        
	}
	result->digit=m;               
	for(i=0;i<m/2;i++)                       
	{
		t=result->num[i];
		result->num[i]=result->num[m-1-i];
		result->num[m-1-i]=t; 
	} 
  Trim(result);         
   Trim(residue);
   	printf("�̣�");
	BPrint(result);
	 printf("\t������");
	 BPrint(residue); 
     printf("\n");
 }
 