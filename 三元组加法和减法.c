#include <stdio.h>
#include <stdlib.h>
#include  <malloc.h>
#define MAXSIZE 1000
typedef struct {
	int row,col;
	int  value;
}Triple;
typedef struct {
	Triple data[MAXSIZE+1];
	int rows,cols,nums;
}TSMatrix;
 TSMatrix *Transpose(TSMatrix *A,TSMatrix *B);
 void yunsuan(TSMatrix *A,TSMatrix *B,TSMatrix *C);
 TSMatrix  *ad(TSMatrix *A,TSMatrix *B,TSMatrix *C);
TSMatrix  *su(TSMatrix *A,TSMatrix *B,TSMatrix *C);
void output(TSMatrix *A);

void main()
{
	 TSMatrix *A,*B,*C;
	 int i;
	 A=(TSMatrix *)malloc(sizeof(TSMatrix));
	 B=(TSMatrix *)malloc(sizeof(TSMatrix));
	 C=(TSMatrix *)malloc(sizeof(TSMatrix));
	 printf("请输入A总行数,总列数,非零元素总数:\n");
	scanf("%d %d %d",&A->rows,&A->cols,&A->nums);
	printf("请输入row,col,value:\n");
     for(i=1;i<=A->nums;i++)
	    scanf("%d %d %d",&A->data[i].row,&A->data[i].col,&A->data[i].value);
	 printf("矩阵A为:\n");
	 output(A);
     printf("\n");
     printf("请输入B总行数,总列数,非零元素总数:\n");
	scanf("%d %d %d",&B->rows,&B->cols,&B->nums);
	printf("请输入row,col,value:\n");
	for(i=1;i<=B->nums;i++)
	 scanf("%d %d %d",&B->data[i].row,&B->data[i].col,&B->data[i].value);
	 printf("矩阵B为:\n");
	 output(B);
     yunsuan(A,B,C);
	
	
	
}
TSMatrix  *Transpose(TSMatrix *A,TSMatrix *C)//逆置
  {
	  int num[MAXSIZE],position[MAXSIZE];
	  int p,col,t,q;
	  C->rows=A->cols;
       C->cols=A->rows;
        C->nums=A->nums;
		if(C->nums)
		{
			for(col=1;col<=A->cols;col++)
				num[col]=0;
			for(t=1;t<=A->nums;t++)
				num[A->data[t].col]++;
			position[1]=1;
			for(col=2;col<=A->cols;col++)
				position[col]=position[col-1]+num[col-1];
			for(p=1;p<=A->nums;p++)
			{
				col=A->data[p].col;
				q=position[col];
				C->data[q].row=A->data[p].col;
				C->data[q].col=A->data[p].row;
				C->data[q].value=A->data[p].value;
				position[col]++;
			}
		}
		return(C);
		}

void yunsuan(TSMatrix *A,TSMatrix *B,TSMatrix *C)//运算
{
	
	char ch;
	printf("请输入运算符号:");fflush(stdin);
	scanf("%c",&ch);
	if(A->rows==B->rows&&A->cols==B->cols)
	{
		
	       switch(ch){
        	case '+': C=ad(A,B,C);printf("A+B=:\n");output(C);break;
			case '-': C=su(A,B,C);printf("A-B=:\n");output(C);break;
			default:printf("error\n");
		   }
			 
		 
	}
	else
		printf("输入错误,不能进行运算!");
}

TSMatrix  *ad(TSMatrix *A,TSMatrix *B,TSMatrix *C)//加法
 {
    
	 int i,j,k;
	 i=1;
	 j=1;
	 k=1;
	while(i<=A->nums&&j<=B->nums)
	{
        if(A->data[i].row<B->data[j].row)
		{
			C->data[k]=A->data[i];
			k++;
			i++;
		}
		else if(A->data[i].row>B->data[j].row)
		{
		   C->data[k]=B->data[j];
		   k++;
	       j++;                                        
		}
		else{
			if(A->data[i].col<B->data[j].col)
			{
				C->data[k]=A->data[i];
				k++;
				i++;
			}
			else if(A->data[i].col>B->data[j].col)
			{
					C->data[k]=B->data[j];
				    k++;
				    j++;
			}
			else{
				if(A->data[i].value+B->data[j].value!=0)
				{
					C->data[k].col=A->data[i].col;
					C->data[k].row=A->data[i].row;
					C->data[k].value=A->data[i].value+B->data[j].value;
					k++;
				}
				i++;
				j++;
			}
		}
	}

	while(i<=A->nums)
		C->data[k++]=A->data[i++];
	while(j<=B->nums)
		C->data[k++]=B->data[j++];
	  C->nums=k;
	  C->cols=A->cols;
	  C->rows=B->rows;
	  return(C);
 }
TSMatrix  *su(TSMatrix *A,TSMatrix *B,TSMatrix *C)//减法
 {
    
	 int i,j,k;
	 i=1;
	 j=1;
	 k=1;
	while(i<=A->nums&&j<=B->nums)
	{
        if(A->data[i].row<B->data[j].row)
		{
			C->data[k]=A->data[i];
			k++;
			i++;
		}
		else if(A->data[i].row>B->data[j].row)
		{
		   C->data[k]=B->data[j];
        
		   k++;
	       j++;                                        
		}
		else{
			if(A->data[i].col<B->data[j].col)
			{
				C->data[k]=A->data[i];
				k++;
				i++;
			}
			else if(A->data[i].col>B->data[j].col)
			{
					C->data[k]=B->data[j];
				    k++;
				    j++;
			}
			else{
				if(A->data[i].value-B->data[j].value!=0)
				{
					C->data[k].col=A->data[i].col;
					C->data[k].row=A->data[i].row;
					C->data[k].value=A->data[i].value-B->data[j].value;
					k++;
				}
				i++;
				j++;
			}
		}
	}

	while(i<=A->nums)
	{
	 C->data[k].value=-A->data[i].value;
	 C->data[k].col=A->data[i].col;
	 C->data[k].row=A->data[i].row;
	  k++;
	  i++;
	  
	   }

	while(j<=B->nums)
	{
		C->data[k].value=-B->data[j].value;
	     C->data[k].col=B->data[j].col;
	   C->data[k].row=B->data[j].row;
	   k++;
	   j++;
	
	}
	  C->nums=k;
	  C->cols=A->cols;
	  C->rows=B->rows;
	  return(C);
 }


void output(TSMatrix *A)//以矩阵形式输出
{
	int i,j,n;
	n=1;
	for(i=1;i<=A->rows;i++)
	{
		for(j=1;j<=A->cols;j++)
		{
			if(A->data[n].row==i&&A->data[n].col==j)
			{
			   
			   printf("%5d",A->data[n].value);
				n++;
			}
			else
				printf("%5d",0);
		}
		printf("\n");
	}
}


	
