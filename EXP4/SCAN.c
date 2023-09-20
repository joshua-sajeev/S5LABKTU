#include<math.h>
#include<stdio.h>
#include<stdlib.h>
void main()
	{
	int r[100],i,j,n,t=0,h,s,temp,index;
	printf("Enter no.of request: ");
	scanf("%d",&n);
	printf("Enter sequence of request: ");
	for(i=0;i<n;i++)
		scanf("%d",&r[i]);
	printf("Enter initial head position: ");
	scanf("%d",&h);
	printf("Enter no .of cylinders: ");
	scanf("%d",&s);
	for(i=1;i<n;i++)
		{
		for(j=0;j<n-i;j++)
		{
			if(r[j]>r[j+1])
			{
				temp=r[j];
				r[j]=r[j+1];
				r[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(h<r[i])
		{
			index=i;
			break;
		}
	}
	printf(" %d",h);
	for(i=index;i<n;i++)
	{
		printf(" %d",r[i]);
		t=t+abs(r[i]-h);
		h=r[i];
	}
	t=t+abs((s-1)-r[i-1]);
	h=s-1;
	printf(" %d",h);
	for(i=index-1;i>=0;i--)
	{
		printf(" %d",r[i]);
		t=t+abs(r[i]-h);
		h=r[i];
	}
	printf("\nTotal Seek time=%d\n",t);
}
