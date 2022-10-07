#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 10
int G[MAX][MAX],i,j,n; // G holo graph    n holo number of vertices
char u;
void dijkstra(int G[MAX][MAX],int n,int startnode)//original function
{
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	//cost[][]=sobar distance store rakhbe , distance[]= start node theke sobar distance rakhbe , pred[]=original path ta store korbe 
	int visited[MAX],count,mindistance,nextnode,i,j;
	//visited[]=kon kon vertex already included dekhar jonno, count= sobkota vertex holo kina dekhar 
	//mindistance= oi vertex theke shortest path ,nextnode= oi vertex theke shortest path wala node (mane er por jeta theke jabo) 
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(G[i][j]==0)
				cost[i][j]=INFINITY;// non adjaccent guloke infinty banalam karon initially tader distance infinity i thake
			else
				cost[i][j]=G[i][j];// onno gulo normal rekhe dilam
		}
	}
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];// startnode er respect e distance array ta initialize korlam
		pred[i]=startnode;// sobar parent startnode ke banalam {karon ota thekei son=bar kache jete lagbe}
		visited[i]=0;// sob visited ke 0 banalam (ekhane 0 mane visited hoyni 1 mane hoise)
	}
	distance[startnode]=0;//startnode theke nijer distance 0
	visited[startnode]=1;// startnode already visited 
	count=1;// ekta vertex visit hoye gelo(startnode ta)
	while(count<n-1)//(n-2) ta khana dekhbo cazz ekbare 2 to kore vertex(u,v) dekhi to (n-1) khana dekhte hbe 
							//ar start vertex tao dekhte hbena tai (n-1-1)  
	{
		mindistance=INFINITY;
		for(i=0;i<n;i++)
		{
			if(distance[i]<mindistance &&! visited[i])//je vertex gulo cover hoyni tar moddhe theke 
														//minimum distance ta khujlam ar next sei vertex ta nextnode e rklm
			{
				mindistance=distance[i];
				nextnode=i;
			}
		}
		visited[nextnode]=1;// nextnode ta visited hlo
		for(i=0;i<n;i++)//same way te nextnode er adjacent gulo dekhbo
		{
			if(!visited[i])//jodi already included na hoy
			{
				//agertay asar cost ar ekhoner minimum distance er sum ta jodi ager theke kom hoy mane age theke onno optimised path jodi pai
				if(mindistance+cost[nextnode][i]<distance[i])
				{		
					distance[i]=mindistance+cost[nextnode][i];//notun distance update koro
					pred[i]=nextnode;// pred array te notun path ta store koro  
				}	
			}
		}
	count++;//ekta kore vertex cover hoye gelo tai count take baralam
	}
	//ebar print korar jonno
	for(i=0;i<n;i++)
	{
		if(i!=startnode)//startnode theke startnode jabar dorkar nei tai ota baad
		{
			printf("\nDistance of node %c= %d",(i+65),distance[i]);
      		printf("\nPath= %c",(i+65));
			j=i;//jetay jabo seita age print kore dilam
			do //do while cazz startnode ta theke suru bole otao print korte hbe ar kono condition vaba gelona
			{
				j=pred[j];//pred array tei to path store ache min distance ta jar(i) tar baba pred[i] ta
				printf("<-%c",(j+65));
			}while(j!=startnode);//j jotokkhon na startnode hocche chalao
		}
	}
}
 
void read()//File theke porar jonno function
{
	FILE *fp;
	fp=fopen("Dijkstra_input.txt","r");
	if(fp==NULL)
	{
		printf("file not in \n");
		return;
	}
	else
	{
		int i,j;
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
int main()//driver code
{
	read();
	printf("\nEnter the starting node: ");
	scanf("%c",&u);
	u=u-65;
	dijkstra(G,n,u);
	return 0;
}
 