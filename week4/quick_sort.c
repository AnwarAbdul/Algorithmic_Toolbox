#include<stdio.h>

int partition(int *a,int l, int r)
{
	int i,j,pivot,temp;
	j = l;
	pivot = a[l];
	printf("\nPivot = %d, l =%d, r= %d\n",pivot,l,r);
	for(i=l+1;i<=r;i++)
	{
		printf("\ni = %d\n",i);
		if(pivot >= a[i])
		{
			j = j+1;
			printf("\nPivot >= a[i]\n");
			printf("\nBefore the swap, a[j] = a[%d] = %d; a[i] = a[%d] = %d\n",j,a[j],i,a[i]);
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			printf("\nAfter swap of next element after current 'j' and current 'i', a[j] = a[%d] = %d; a[i] = a[%d] = %d\n",j,a[j],i,a[i]);
		}
	}
	temp = a[l];
	a[l] = a[j];
	a[j] = temp;
	printf("\n'm' generated is %d\n",j);
	return j;

}

void quick_sort(int *a,int l, int r)
{
	int m;
	if(l >= r)
		return;
	else
	{
		m = partition(a,l,r);
		quick_sort(a,l,m-1);
		quick_sort(a,m+1,r);
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
	
