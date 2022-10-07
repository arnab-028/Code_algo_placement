#include<stdio.h>
#include<stdlib.h>
#define INF 999
int n,weight[10][10],parent[10],c=1,a,b,u,v,min;
void read()
{
	FILE *fp;
	fp=fopen("kru.txt","r");
	if(fp==NULL)
	{
		printf("file not in \n");
		return;
	}
	else
	{
		fscanf(fp,"%d",&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)

			{
				fscanf(fp,"%d",&weight[i][j]);
			}
		}
	}
}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)

{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
int main()
{
	read();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(weight[i][j]==0)
				weight[i][j]=INF;	
		}
	}
	printf("The edges of minimum cost spanning tree are\n");
	int i,j;
	while(c<n)
	{
		for(i=0,min=INF;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(weight[i][j]<999)
				{
					min=weight[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
			printf("%d edge (%c,%c) =%d\n",c++,a+65,b+65,min);
		weight[a][b]=weight[b][a]=INF;
	}
}