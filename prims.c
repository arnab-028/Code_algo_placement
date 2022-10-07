#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define INFINITY 9999
#define MAX 10
int G[MAX][MAX],n,i,j;
void read()//File theke porar jonno function
{
	int i,j;
	FILE *fp;
	fp=fopen("kru.txt","r");
	if(fp==NULL)
	{
		printf("ERROR\n");
		return;
	}
	else
	{
		fscanf(fp,"%d",&n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				fscanf(fp,"%d",&G[i][j]);

			}
		}
	}
}
int minkey(int *key,bool *myset)//nonvisited gulo theke minimum distance wala khujar jonno
{
	int min=INFINITY,index;
	for(i=0;i<n;i++)//pati kadane's algo
	{
		if(myset[i]==false && key[i]<min)
		{
			min=key[i];
			index=i;
		}
	}
	return index;//minimum tar index return koro
}
void printmst(int *parent,int G[MAX][MAX])//pati print marlam
{
	printf("edge \t weight\n");
	for(i=1;i<n;i++)//i =1 theke cazz 0 theke 0 kono edge to hbena 
	printf("%c->%c\t%d\n",(parent[i]+65),(i+65),G[i][parent[i]]);
}
void prims(int G[MAX][MAX])//original function
{
	int i;
	int parent[n];//konta theke konta edge connect hbe seitar jonno [(u,v) edge hole parent[v]=u]
	int key[n]; // sobkota node er keyvalue mane ager nodeta theke aste minimum khorcha(edge value) koto seta store rakhe
	bool myset[n];//node ta include hoise kina 
	for(i=0;i<n;i++)
	{
		key[i]=INFINITY;//initially sobar khorcha infinity
		myset[i]=false;//sobai unvisited;
		//parent[i]=-1;//karo baba nei
	}
	int v;
	key[0]=0;//nijer theke jete khorcha 0
	parent[0]=-1;//sobar baba tai baba nei
	for(i=0;i<n-1;i++)//sobkota vertex er jonno dekhbo [n-2 karon ekta edge e 2 to vertex jabe tai n-1-1 ]
	{
		int u=minkey(key,myset);//unvisted node gulor moddhe minimum edge wala tule ano u te
		myset[u]=true;//u ke visited banao
		for(v=0;v<n;v++)//u er adjacent er jonno
		{
			if(G[u][v]!=0 && myset[v]==false && G[u][v]<key[v])//adjacent+nonvisied hole jodi ager theke kom khorchay jai mane G er value key er theke kom hoy
			{
				parent[v]=u;//tahole edge ta solution e add koro
				key[v]=G[u][v];//key ta update koro
			}
 		}
	}
	//print koro
	printmst(parent,G);
}
int main()//driver code
{
	read();
	prims(G);
	return 0;
}