#include<stdio.h>
#include<limits.h>
int n,m=INT_MIN;
struct Job
{
    char id;
    int profit;
    int deadline;
};
struct Job job[20];

void find_maxDuration()
{
    for(int i=0;i<n;i++)
    {
        if(job[i].deadline>m)
        {
            m=job[i].deadline;
        }
    }
}

void input_jobs()
{
    for(int i=0;i<n;i++)
    {
        printf("\nFor job %c :-\n",(65+i));
        job[i].id=(char)(65+i);

        printf("Enter the profit : ");
        scanf("%d",&job[i].profit);

        printf("Enter the deadline : ");
        scanf("%d",&job[i].deadline);
    }
}

void merge_jobs(int low,int mid,int high)
{
    int i=low,j=mid+1,k=0;
    struct Job b[high-low+1];

    while(i<=mid && j<=high)
    {
        if(job[i].profit>=job[j].profit)
        {
            b[k++]=job[i++];
        }
        else
        {
            b[k++]=job[j++];
        }
    }
    while(i<=mid)
    {
        b[k++]=job[i++];
    }
    while(j<=high)
    {
        b[k++]=job[j++];
    }
    k=0;
    for(int a=low;a<=high;a++)
    {
        job[a]=b[k++];
    }
}

void mergeSort_jobs(int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort_jobs(low,mid);
        mergeSort_jobs(mid+1,high);
        merge_jobs(low,mid,high);
    }
}

void Job_Scheduling()
{
    int slot[m+1];
    double p=0.0;
    int count=0,i=0;

    for(int i=1;i<=m;i++)
    {
        slot[i]=-1;
    }
    printf("\nThe jobs scheduled are :-\n",n);
    
    for(int i=0;i<n;i++)
    {
        for(int j=job[i].deadline;j>=1;j--)
        {
            if(slot[j]==-1)
            {
                slot[j]=i;
                p=p+job[i].profit;
                printf("\n%d. Job %c (Profit = Rs.%d)",++count,job[i].id,job[i].profit);
                if(count==m)
                {
                    goto label;
                }
                break;
            }
        }
    }
    label:printf("\n\nThe maximized profit is Rs.%lf",p);
}

void main()
{
    printf("\n\n ------- : JOB SCHEDULING : ------- \n\n");
    printf("\nEnter the number of jobs : ");
    scanf("%d",&n);
    
    input_jobs();
    mergeSort_jobs(0,n-1);
    find_maxDuration();
    Job_Scheduling();
}