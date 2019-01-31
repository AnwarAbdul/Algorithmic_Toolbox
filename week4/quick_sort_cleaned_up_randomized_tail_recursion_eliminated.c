#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int *a,int l, int r)
{
	int i,j,pivot,temp;
	j = l;
	pivot = a[l];
	for(i=l+1;i<=r;i++)
	{
		if(pivot >= a[i])
		{
			j = j+1;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[l];
	a[l] = a[j];
	a[j] = temp;
	return j;

}

void quick_sort(int *a,int l, int r)
{
	int m;
	int x;
	int temp;

	while(l < r)
	{
		srand(time(NULL));
		x = l + rand() % (r-l);
		temp = a[x];
		a[x] = a[l];
		a[l] = temp;

		m = partition(a,l,r);
	
		if((m-l) < (r-m))
		{
			quick_sort(a,l,m-1);
			l = m+1;
		}
		else
		{
			quick_sort(a,m+1,r);
			r = m-1;
		}
	}
}


int main()
{
	int n,i,l,r;
	scanf("%d",&n);
	int a[n];l=0,r=n-1;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	quick_sort(a,l,r);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
	
