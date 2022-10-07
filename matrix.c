#include<stdio.h>
#define INF 999999
int s[10][10];

void pop(int i, int j)
{
	if(i==j){
		printf("A%d",i);
	}
	else{
		printf("(");
		pop(i,s[i][j]);
		pop(s[i][j]+1,j);
		printf(")");
	}
}

int matrixChainMul(int arr[], int n)
{
	int i;
	int aux[n][n];
	//int s[n][n];
	for(i=0;i<n;i++)
		aux[i][i]=0;
	
	int l,a,b,c,cost;
	for(l=2;l<n;l++){
		for(a=1;a<n-l+1;a++){
			b=a+l-1;
			aux[a][b]=INF;
			for(c=a;c<=b-1;c++){
				cost= aux[a][c]+aux[c+1][b]+(arr[a-1]*arr[c]*arr[b]);
				if(cost<aux[a][b]){
					aux[a][b]=cost;
					s[a][b]=c;
				}
			}
		}
	}
	int r,x;
	for(r=1;r<n;r++){
		for(x=0;x<n;x++){
			if(r>x)
				printf("\t");
			else
				printf("%d\t",aux[r][x]);
		}
		printf("\n");
	}
	printf("\n");
	for(r=1;r<n;r++){
		for(x=0;x<n;x++){
			if(r>=x)
				printf("\t");
			else
				printf("%d\t",s[r][x]);
		}
		printf("\n");
	}
	return aux[1][n-1];
}

int main()
{
	int p;
	printf("Enter the number of matrixes: ");
	scanf("%d",&p);
	
	int n=p+1;
	int arr[n];
	
	int i;
	printf("Enter: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
		
	int res=matrixChainMul(arr,n);
	printf("Minimum number of multiplication is: %d \n",res);
	pop(1,n-1);
	return 0;
}