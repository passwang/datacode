#include <stdio.h> 
#include <malloc.h>
#include <string.h> 
#define N 10
typedef struct Node{  
    char data;  
    struct Node *lchild;  
    struct Node *rchild;  
} Node;  
  
Node *Convert(char pre[], int pre_s, int pre_e,  
              char in [], int in_s , int in_e )  
{  
	int i;
    Node *p;
    if(in_s > in_e) return NULL;  
  
    
    for(i=in_s;i<in_e&&in[i]!=pre[pre_s];i++);  
  
  
    p = (Node *)malloc(sizeof(Node));  
    p->data = pre[pre_s];  
    p->lchild = Convert(pre, pre_s+1, pre_s+i-in_s,  
                        in,  in_s,i-1);  
    p->rchild = Convert(pre, pre_s+i-in_s+1,pre_e,  
                        in,  i+1,in_e);  
  
    return p;  
}  
void PreTranverse(Node *head)  
{  
    if(!head)return ;  
    printf("%c\t",head->data);  
    PreTranverse(head->lchild);  
    PreTranverse(head->rchild);  
    return;  
}  
void InTranverse(Node *head)  
{  
    if(!head)return ;  
    PreTranverse(head->lchild);  
    printf("%c\t",head->data);  
    PreTranverse(head->rchild);  
    return;  
}  
void BackTranverse(Node *head)  
{  
    if(!head)return;  
    BackTranverse(head->lchild);  
    BackTranverse(head->rchild);  
    printf("%c\t",head->data);  
    return;  
}  
  
int main(int argc, char *argv[])  
{  

    char pre[N];  
    char in[N];
	Node *head = NULL;
	printf("请输入先序序列:");
	scanf("%s",pre);
	printf("请输入中序序列:");
	scanf("%s",in);
      
  
    head = Convert(pre,0,strlen(pre)-1,  
                   in ,0,strlen(in)-1);  
    BackTranverse(head);  
    printf("\n");  
  
}