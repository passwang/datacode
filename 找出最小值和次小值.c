#include <stdio.h>
#define N 20
void main()
{
	int a[N],i,n,x,y;
	printf("Qingshuru  n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
       x=a[1];//xΪ��Сֵ
	   y=a[2];//yΪ��Сֵ
	for(i=2;i<=n;i++)
	{
		if(x>a[i])
		{
			y=x;
			x=a[i];
		}
		else if(y>a[i])
		{
			y=a[i];

		}
		
	}
	printf("%d,%d",x,y);
}
