#include <stdio.h>
#define INF 9999
int m[100][100];
int s[100][100];
void pop(int i,int j)
{
	if(i==j)
	{
		printf("A%d",i);
	}
	else
	{
		printf("(");
		pop(i,s[i][j]);
		pop(s[i][j]+1,j);
		printf(")");
	}
}
void matrixchainorder(int p[],int n)
{
	int cost,l,i,j,k;
	for(i=1;i<=n;i++)
	{
		m[i][i]=0;
	}
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=INF;
			for(k=i;k<=j-1;k++)
			{
				cost=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(cost<m[i][j])
				{
					m[i][j]=cost;
					s[i][j]=k;
				}
			}
		}
	}
}
int main()
{
	int i,j,n;
	printf("Enter the number of matrix:");
	scanf("%d",&n);
	int p[100];
	printf("Enter the dimension of matrix: ");
	for(i=0;i<=n;i++)
	{
		scanf("%d",&p[i]);
	}
	matrixchainorder(p,n);
	pop(1,n);
	printf("\n");
	return 0;
}