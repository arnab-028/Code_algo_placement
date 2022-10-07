#include <stdio.h>
int n;


struct Job{
	int id;
	int dead;
	int profit;
};
struct Job j[10];
void sort(){
	
  struct Job temp;
  int i,k;
  for(i=1;i<=n;i++){
    for(k=i+1;k<=n;k++){
      if(j[i].profit<j[k].profit){
        temp=j[i];
        j[i]=j[k];
        j[k]=temp;
      }
    }
}
  printf("After Sorting \n");
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",j[i].id,j[i].dead,j[i].profit);
  }
}
void readGraph(){
	printf("Enter the number of jobs:");
	int i;
	scanf("%d",&n);
	printf("Enter Job Id   Job Deadline   Job Profit\n");
	for(i=1;i<=n;i++){
		scanf("%d %d %d",&j[i].id,&j[i].dead,&j[i].profit);
	}
	sort();
}
int min(int x,int y){
	if(x>y) 
		return y;
	return x;
}
void jsd(){
	
	int slot[n];
	int x[n],i=0,k;
	int result[n];
	for(i=1;i<=n;i++){
		slot[i]=0;
		x[i]=0;
	}
	
	for(i=1;i<=n;i++){
		for(k=min(j[i].dead,n);k>0;k--){
			if(slot[k]==0){
				slot[k]=1;			// slot is full
				x[k]=i;			   // indx of the job in the srtuct array j[]
				result[k]=j[i].id;
				break;
	
		}
	}
	int total=0;
	i=1;
	while(x[i]>0)
	{
		printf("J%d   ",result[i]);
		total+=j[x[i]].profit;
		i++;
	}
	printf("\nThe total profit: %d",total);
	
}
}
int main(void){
	
	readGraph();
	jsd();
	return 0;
}


