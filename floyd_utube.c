#include<stdio.h>
#include<stdlib.h>
#define inf 999
int n;
int graph[n][n];
void display(int dist[][n]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(dist[i][j]==999)
				printf("inf\t");
			else
				printf("%d\t",dist[i][j]);
		}
		printf("\n");
	}
}
void floyd(int graph[][n]){
	int i,j,k,dist[n][n];
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				dist[i][j]=graph[i][j];
			}
		}
		
		for(k=0;k<n;k++){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(dist[i][j]>dist[i][k]+dist[k][j]){
						dist[i][j]=dist[i][k]+dist[k][j];
					}
				}
			}
			printf("\nD%d:\n",k+1);
			display(dist);
		}
		
}
void read()//File theke porar jonno function
{
	FILE *fp;
	fp=fopen("floyd.txt","r");
	if(fp==NULL)
	{
		printf("file not in \n");
		return;
	}
	else
	{
		int i,j;
		fscanf(fp,"%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				fscanf(fp,"%d",&graph[i][j]);

			}
		}
	}
  fclose(fp);
}
int main(){
	read();
	display(graph);
	floyd(graph);
	return 0;
}