#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void count(int *a,int *count_array,int n,int bound)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		count_array[a[i]-1] += 1;
	}
		
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;int a[n];
	int bound=10;
	srand(time(NULL));
	for(i=0;i<n;i++)
		a[i] = rand() % bound + 1;
       	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");	
	int count_array[bound];
	for(i=0;i<bound;i++)
		count_array[i] = 0;
	count(a,count_array,n,bound);
	for(i=0;i<bound;i++)
	{
		while(count_array[i]!=0)
		{
			printf("%d ",i+1);
			count_array[i]--;
		}
	}

	return 0;
}
