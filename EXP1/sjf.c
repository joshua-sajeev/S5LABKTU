#include<stdio.h>
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int main()
{
	int i,n,j,k,at[50],bt[50],ct[50]={0},tat[50],wt[50],sum=0,p[50];
	float ttat=0,atat,awt,twt=0;
	printf("Enter the no of process: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i+1;
		printf("Enter the arrival time of process: %d ",p[i]);
		scanf("%d",&at[i]);
		printf("Enter the burst time of process: %d ",p[i]);
		scanf("%d",&bt[i]);
	}
	printf("\nData entered\n");
	printf("PID \t\tAT\t\tBT\n");
	for(i=0;i<n;i++)
	{
		printf("p%d\t\t%d\t\t%d\n",p[i],at[i],bt[i]);
	}
	for(j=1;j<n;j++)
	{
		for(k=0;k<n-j;k++)
		{
			if(at[k]>at[k+1])
			{
				swap(&p[k],&p[k+1]);
				swap(&at[k],&at[k+1]);
				swap(&bt[k],&bt[k+1]);
			}
		}
	}
	for(j=1;j<n-1;j++)
	{
		for(k=1;k<n-j;k++)
		{
			if(bt[k]>bt[k+1])
			{
				swap(&p[k],&p[k+1]);
				swap(&at[k],&at[k+1]);
				swap(&bt[k],&bt[k+1]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		sum=sum+bt[i];
		ct[i]=ct[i]+sum;
		tat[i]=ct[i]-at[i];
		ttat=tat[i]+ttat;
		wt[i]=tat[i]-bt[i];
		twt=twt+wt[i];
	}
	printf("After the completion\n");
	printf("PID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	atat=ttat/n;
	awt=twt/n;
	printf("average TAT is: :%0.2f\n",atat);
	printf("average WAT is: %0.2f\n",awt);
}
