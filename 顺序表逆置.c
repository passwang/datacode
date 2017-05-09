#include <stdio.h>
#define N 16
void change(int a[N],int n);
void main()
{
	int a[N],n,i;
	scanf("%d",&n);
   for(i=0;i<n;i++)

	   scanf("%d",&a[i]);
      change(a,n);
   for(i=0;i<n;i++)
	   printf("%2d",a[i]);
   printf("\n");
}
  void change(int a[N],int n)
{ 
	  int j,t,k;
	  k=n;
  for(j=0;j<n/2;j++)
  {  
	  t=a[j];
	  a[j]=a[k-1];
	  a[k-1]=t;
	   k--;
  }
 
}
