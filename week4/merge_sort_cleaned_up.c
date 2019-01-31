#include<stdio.h>
void merge(int *a, int al, int n)
{
	int i,j,k;
	int b[n/2],c[n-n/2];
	for(i=al;i<al+n/2;i++)
		b[i-al] = a[i];
	for(j=al+n/2;j<al+n;j++)
		c[j-al-n/2] = a[j];
	i=j=0;
	k=al;
	while((i<n/2) && (j<(n-n/2)))
	{
		if(b[i] < c[j])
		{
			a[k] = b[i];
			k++;
			i++;
		}
		else
		{
			a[k] = c[j];
			k++;
			j++;
		}
	}
	while(i < n/2)
	{
		a[k] = b[i];
		i++;
		k++;
	}
	while(j < (n-n/2))
	{
		a[k] = c[j];
		j++;
		k++;
	}
	
}

void merge_sort(int *a, int l, int n)
{
	if(n == 1)
		return;
	else
	{
		int m = n/2;
		merge_sort(a,l,n/2);
		merge_sort(a,l+m,n-n/2);
		merge(a,l,n);
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	int i,a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	merge_sort(a,0,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}

