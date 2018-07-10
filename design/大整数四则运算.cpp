#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>

/*----------------大整数描述---------------*/
typedef struct biginteger
{
	char *num;                //指向长整数数组（序号0中保存着最高位） 
	char character;               //符号（1表示正数，-1表示负数） 
	int digit;                 //保存该数的位数（实际位数） 
}BigInteger,*pb; 

/*------------函数声明部分---------------------*/

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

/*--------------主函数部分------------------*/

int main()
 {
 	BigInteger data1,data2,result;              //参与运算的数1,2，结果，余数 
	 int i=0,len;
     int flage;
     printf("\n==================================大整数计算器 =================================\n"); 
	 printf("输入最大数的位数：");
	 scanf("%d",&len);
	 data1.num=(char *)malloc(sizeof(char) * (len+1));
     data1.digit=len +1;
	 data2.num=(char *)malloc(sizeof(char) * (len+1));
     data2.digit=len+1;
	 result.num=(char *)malloc(sizeof(char) * (2*len+1));
	 result.digit=2*len+1;

	 for(i=0;i<result.digit;i++)            
	 	result.num[i]=0;
	 printf("请输入第一个数:\t");
     scanf("%s",data1.num); 
	 printf("请输入第二个数:\t");
	 scanf("%s",data2.num);
	 Trans(&data1);
     Trans(&data2);
	printf("1.加法 2.减法 3.乘法 4.除法 0.退出\n"); 
	printf("请从1~4中选择:");
	fflush(stdin);            //清空缓存集 
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
				printf("除数不能为0！\n");
			else
				Div(&data1,&data2);    
			break; 
		case 0:exit(0);
	}
	if(flage==1||flage==2||flage==3)
	{	printf("结果：");
		BPrint(&result); 
		printf("\n");
	}

	return 0;
 }

/*----------------分函数部分-------------------*/

void Trans(pb data1)    //将字符串转为数字表示 
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
		if(data1->num[i]>='0' && data1->num[i] <='9')     //数字为0~9 
		{
			temp[k]=data1->num[i]-'0';                 
			k++; 
		} 
		i++;
	}     
	
	for(i=0;i<data1->digit;i++)     
		data1->num[i]=0;
	data1->digit=k;                     
	for(i=0,k--;k>=0;k--,i++)          //将临时数组各位置反置保存到数组num中 
		data1->num[i]=temp[k];
	Trim(data1);                   
}

void Trim(pb data1)           //整理大整数，去掉前面多余的0 
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

void BPrint(pb result)      //输出大整数 
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

int Equal(pb data1,pb data2)         //比较绝对值大小 
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

void Add(pb data1,pb data2,pb result)    // 加法函数。但是不执行具体的加法算法
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
	if(data1->character * data2->character <0)     //同号执行加法，异号调用减法函数     
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

void Add1(pb data1,pb data2,pb result)     //加法算法  
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

void Sub(pb data1,pb data2,pb result)     //异号减法、执行加法 
{
	data2->character =-1 * data2 ->character;       
	Add(data1,data2,result);          
} 

void Sub1(pb data1,pb data2,pb result)     //同号相减函数
{
	int i,borrow;
	result->character =data1->character;         //结果符号 
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



void Multiply(pb data1,pb data2,pb result)    //乘法函数  
{
	char carry,temp;//进位数
	int i,j,pos;//位置
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


void Div(pb data1,pb data2)                              //除法函数 
{
    pb result,residue;
	int i,j,k,m;               //k保存试商结果，m保存商的位数 执行减法
	char t;
	result=(pb)malloc(sizeof(BigInteger));
    residue=(pb)malloc(sizeof(BigInteger));
	result->character = data1->character * data2->character;        //商的符号 
	for(i=0;i<residue->digit;i++)            //将余数全部清0 
		residue->num[i]=0;
	m=0;
	for(i=data1->digit-1;i>=0;i--)
	{
		residue->digit=data2->digit+1;       
		for(j=data2->digit-1;j>0;j--)              
		residue->num[j]=residue->num[j-1];
    	residue->num[0]=data1->num[i];          
	 Trim(residue);                  
		k=0;   //试商 
		while(Equal(residue,data2)>=0)      
		{
		Sub1(residue,data2,residue);     
			k++;                       //试商加1 
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
   	printf("商：");
	BPrint(result);
	 printf("\t余数：");
	 BPrint(residue); 
     printf("\n");
 }
 