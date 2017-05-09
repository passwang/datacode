#include <stdio.h>
#define N 16
 void f(int a[N][N],int m,int n);
  void main()
  {
	  int a[N][N];
	  int m,n,i,j;
     printf("请输入m:\n");
	 scanf("%d",&m);
      printf("请输入n:\n");
	 scanf("%d",&n);
	 for(i=0;i<m;i++)
		 for(j=0;j<n;j++)
			 scanf("%d",&a[i][j]);
		 f(a,m,n);
  }
  void f(int a[N][N],int m,int n)
  {
      int i,j,k,minrow,mincol,maxrow,maxcol,min,max,count;
	   min=a[0][0];
	   count=0;
	    for(i=0;i<m;i++)
		{  min=a[i][0];
			 for(j=0;j<n;j++)
			 {
			 if(a[i][j]<=min)
			 {
				 min=a[i][j];
				 minrow=i;
				 mincol=j;
			 }
			}
			 max=a[0][mincol];
              for(k=0;k<m;k++)
			  {
				 if(a[k][mincol]>=max)
				 {
					 max=a[k][mincol];
					 maxrow=k;
				

				 }
			  }
			 
				 if(minrow==maxrow)
				 {
					 count++;
					 printf("%d\n",a[minrow][mincol]);
				 }
			
	
		}
		if(count==0)
			 printf("没有鞍点\n");

 }
                      



