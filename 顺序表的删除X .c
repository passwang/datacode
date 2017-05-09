#include <stdio.h>
#define N 16
int delate(int a[N],int x,int n);

void main()
{
	int a[N],n,i,x,k;
    scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("请输入要删除x:");
	scanf("%d",&x);
   k=delate(a,x,n);
   	for(i=0;i<k;i++)
	{
		printf("%2d",a[i]);
	}
	printf("\n");
}
int delate(int a[N],int x,int n)
{
	int i,j,k;
	k=n;
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			for(j=i;j<n;j++)
				a[j]=a[j+1];
			n--;
			i--;
		}
	
	}
	if(k==n)
		printf("不存在x\n");
	return(n);
}
			

