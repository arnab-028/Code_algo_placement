#include<stdio.h>
#include<stdbool.h>
int n;
struct job{
	char id;
	int profit;
	int deadline;
	
};

struct job x[10];
void display()
{
	printf("%8s%8s\t%8s\n","Job id","profit","deadline");
	int i;
	for (i=1;i<=n;i++)
	{
		printf("%8c%8d%8d\n",x[i].id,x[i].profit,x[i].deadline);
	}
}
void sort()
{
	int i,j;
	struct job temp;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(x[i].profit<x[j].profit)
			{
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}
	
	}
	printf("After sorting the jobs");
	for(i=1; i<=n; i++){
		printf("%c %d %d\n",  x[i].id, x[i].profit, x[i].deadline);
	}
}
void read_graph(){
	int i;
	printf("The number of jobs");
	scanf("%d", &n);
	for(i=1; i<=n;i++){
		scanf("%c%d%d", &x[i].id, &x[i].profit, &x[i].deadline);
	}
	sort();
}
int minimum(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int jsd()
{
	int a[n];
	bool slot[n];
	int i,j,s,tp=0;
	for(i=1;i<=n;i++)
	{
		slot[i]=false;
		a[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		s=minimum(x[i].deadline,n);
		for(j=s;j>=0;j--)
		{
			if(slot[j]==false)
			{
				a[j]=i;
				slot[j]=true;
				tp+=x[a[j]].profit;
				break;
			}
		}
	}
	printf("Performed jobs:");
	for(i=1;i<=n;i++)
	{
		if(slot[i]==true)
		{
			printf("%c ",x[a[i]].id);
		}
	}
	printf("Total profit:%d",tp);
}

int main()
{
	read_graph();
	sort();
	//display();
	//jsd();
	


}
