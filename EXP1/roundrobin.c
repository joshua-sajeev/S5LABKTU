#include<stdio.h>
int q[10],front=-1,rear=-1;
void enq(int m)
{
	if(front==-1)
	{
		front=0;
	}
	rear++;
	q[rear]=m;
}
int deq()
{
	int y=q[front];
	front++;
	return y;
}
void main()
{
	int n,at[10],bt[10],p[10],i,j,k,ct[10]={0},tat[10],wt[10],sum=0,times=0,tq,exist[10]={0},temp[10];
	float awt=0,atat=0,ttat=0,twt=0;
	printf("Enter no.of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)	
	{
		p[i]=i+1;
		printf("Arraival time of P%d :",p[i]);
		scanf("%d",&at[i]);
		printf("Burst time of P%d: ",p[i]);
		scanf("%d",&bt[i]);
		temp[i]=bt[i];
	}
	printf("Entered value \n");
	printf("\tPID\t\tAT\t\tBT\n");
	for(i=0;i<n;i++)
	{
		printf("\tP%d\t\t%d\t\t%d\n",p[i],at[i],bt[i]);
	}
	printf("Enter Time Quantum: ");
	scanf("%d",&tq);
	enq(0);
	exist[0]=1;
	while(front<=rear)
	{
		int l=deq();
		if(bt[l]>=tq)
		{
			bt[l]=bt[l]-tq;
			times=times+tq;
		}
		else
		{
			times=times+bt[l];
			bt[l]=0;
		}
		for(i=0;i<n;i++)
		{
			if(exist[i]==0&&at[i]<=times)
			{
				enq(i);
				exist[i]=1;
			}
		}
		if(bt[l]==0)
		{
			ct[l]=times;
			tat[l]=ct[l]-at[l];
			ttat=ttat+tat[l];
			wt[l]=tat[l]-temp[l];
			twt=twt+wt[l];
		}
		else
		{
			enq(l);
		}
	}
	printf("After the completion\n");
	printf("\tPID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT \n");
	for(i=0;i<n;i++)
	{
		printf("\tP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i],at[i],temp[i],ct[i],tat[i],wt[i]);
	}
	atat=ttat/n;
	awt=twt/n;
	printf("Average TAT=%0.2f ms\n",atat);
	printf("Average WT=%0.2f ms\n",awt);
}
