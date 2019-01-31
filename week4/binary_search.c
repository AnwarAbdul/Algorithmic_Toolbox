#include<stdio.h>

int binary_search(int *a,int low,int high,int key)
{
	int mid = low + (high-low)/2;
	if(low>high)
		return low;
	else if(a[mid] == key)
		return mid;
	else if(key > a[mid])
		return binary_search(a,mid+1,high,key);
	else
		return binary_search(a,low,mid-1,key);
}

int main()
{
	int n,i,j,temp,key;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j] < a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("\n%d.%d",i,a[i]);
	printf("\nEnter element to be searched for\n");
	scanf("%d",&key);
	int pos;
	pos = binary_search(a,0,n-1,key);
	printf("\nElement is located at %d or it can be inserted here\n",pos);
	return 0;
}

