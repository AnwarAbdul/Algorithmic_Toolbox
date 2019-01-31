#include<stdio.h>

int linear_search(int *a, int low, int high, int key)
{
	if(low>=high)
		return -1;
	else if(a[low] == key)
		return low;
	else
		return linear_search(a,low+1,high,key);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int key,pos;
	printf("\nEnter element to be searched for in the array\n");
	scanf("%d",&key);
	pos = linear_search(a,0,n,key);
	printf("\nElement %d is located at index %d in the entered array\n",key,pos);
	return 0;
}
