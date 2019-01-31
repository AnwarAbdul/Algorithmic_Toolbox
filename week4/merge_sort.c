#include<stdio.h>
void merge(int *a, int al, int n)
{
	int i,j,k;
	int b[n/2],c[n-n/2];
	printf("\nInside merge. n = %d, al = %d\n",n,al);
	for(i=al;i<al+n/2;i++)
	{
		b[i-al] = a[i];
		printf("\nInside merge. b[%d] = a[%d]; a[%d] = %d\n",i-al,i,i,a[i]);
	}
	for(j=al+n/2;j<al+n;j++)
	{
		c[j-al-n/2] = a[j];
		printf("\nInside merge. c[%d] = a[%d]; a[%d] = %d\n",j-al-n/2,j,j,a[j]);
	}
	i=j=0;
	k=al;
	while((i<n/2) && (j<(n-n/2)))
	{
		if(b[i] < c[j])
		{
			printf("\nAssigning a[%d] = b[%d], b[%d] = %d\n",k,i,i,b[i]);
			a[k] = b[i];
			printf("\nVerifying... a[%d] = %d\n",k,a[k]);
			k++;
			i++;
		}
		else
		{
			printf("\nAssigning a[%d] = c[%d], c[%d] = %d\n",k,j,j,c[j]);
			a[k] = c[j];
			printf("\nVerifying... a[%d] = %d\n",k,a[k]);
			k++;
			j++;
		}
	}
	while(i < n/2)
	{
		a[k] = b[i];
		i++;
		printf("\nVerifying... a[%d] = %d\n",k,a[k]);
		k++;
	}
	while(j < (n-n/2))
	{
		a[k] = c[j];
		j++;
		printf("\nVerifying... a[%d] = %d\n",k,a[k]);
		k++;
	}
	for(k=al;k<al+n;k++)
	{
		printf("\nInside merge. a[%d] = %d\n",k,a[k]);
	}
	
}

void merge_sort(int *a, int l, int n)
{
	if(n == 1)
	{
		printf("\nIndex of element accessed = %d\n",l);
		return;
	}
	else
	{
		int m = n/2;
		printf("\nPassing 1 start element index = %d, end element index = %d\n",l,l+m-1);
		merge_sort(a,l,n/2);
		printf("\nPassing 2 start element index = %d, end element index = %d\n",l+m,l+n-1);
		merge_sort(a,l+m,n-n/2);
		merge(a,l,n);
	}
}


int main()
{
	int n;
	printf("\nEnter the size of the array\n");
	scanf("%d",&n);
	int i,a[n];
	printf("\nEnter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	merge_sort(a,0,n);
	printf("\nThe sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}

