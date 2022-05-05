#include<iostream>
#include<limits.h>

using namespace std;
void printmco(int **s,int i,int j)
{
	if(i==j)
	 {
	   cout<<"a"<<i;
	  }else 
	 {
	   cout<<"(";
	  printmco(s,i,s[i][j]);
	  printmco(s,s[i][j]+1,j);
	  cout<<")";
}
}
void mco(int p[],int **m,int **s,int n)
{   
    int q;
	for(int i=1;i<=n;i++)
	{
		m[i][i]=0;
	}
	cout<<"\n\n"<<m;
	for(int l=2;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			m[i][j]=9999;
			for(int k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i - 1] * p[k] * p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}



   
}


int main()
{   int n;

	cout<<"enter number of elements";
	cin>>n;
      
	  int *p;
	  p=new int[n+1];
	  int **m;
	  m=new int*[n+1];
	  for(int i=0;i<=n;i++)
	  {
	  	m[i]=new int[n+1];
	  }
	  int **s;
	  s=new int*[n+1];
	  for(int i=0;i<=n;i++)
	  {
	  	s[i]=new int[n+1];
	  }
	   
	 cout<<"enter array";
    	for(int i=0;i<=n;i++)
	{
		cin>>p[i];
	}
		cout<<"\n\n"<<m;


 mco(p,m,s,n);
 cout<<"\n\nMin: "<<m[1][n];
 printmco(s,1,n);
}
