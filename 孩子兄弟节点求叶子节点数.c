#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 20
typedef char datatype;

typedef struct Node{
	datatype data;
	struct Node *FirstChild;
	struct Node *NextSibling;
}BT;
BT *CreatBT();
void Leafnum(BT *root);

int leafnum=0;
char *ch;
void main()
{
  
    char p[64];
	BT *root;
	printf("�����������:\n");
    scanf("%s",p);
    ch= &p[0];
    root=CreatBT();
	Leafnum(root);
	printf("Ҷ�ӽڵ�����%d:\n",leafnum);

	}

BT *CreatBT() //����������
{
	
    BT *root;
    if(*(ch)=='#')
    {
        ch++;
        root=NULL;
    }
    else
    {
        root=(BT*)malloc(sizeof(BT));
        root->data=*(ch++);
        root->FirstChild=CreatBT();
        root->NextSibling=CreatBT();
    }
    return(root);
}
void Leafnum(BT *root)
{
	if(root)
	{
		if(!root->FirstChild)
			leafnum++;
    Leafnum(root->FirstChild);
    Leafnum(root->NextSibling);
	}
}