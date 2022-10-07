#include <stdio.h>
int n;
int a[10];
void swap(int *x,int *y){
	*x=*x^*y;
	*y=*x^*y;
	*x=*x^*y;
}
void heapify(int a[],int n , int i){
	int l=2*i+1;
	int r=2*i+2;
	int largest=i;
	if(l<n && a[l]>a[largest]){
		largest=l;
	}
	if(r<n && a[r]>a[largest]){
		largest=r;
	}
	if(largest!=i){
		swap(&a[i],&a[largest]);
		heapify(a,n,largest);
	}
}
void heapsort(int a[],int n){
	int i;
	for(i=n/2-1;i>=0;i--){
		heapify(a,n,i);
	}
	
	for(i=n-1;i>0;i--){
		swap(&a[0],&a[i]);
		heapify(a,i,0);
	}
}

int main(void){
	int i;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	for(i=0;i<n;i++){
	
		printf("%3d",a[i]);
	}
	return 0;
}
