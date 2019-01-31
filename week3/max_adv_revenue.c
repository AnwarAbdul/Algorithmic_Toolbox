#include<stdio.h>
#include<inttypes.h>

void sort(long int *ar,int n)
{
	int i,j;
	long int temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ar[j] > ar[i])
			{
				temp = ar[j];
				ar[j] = ar[i];
				ar[i] = temp;
			}
		}
	}
}


int main()
{
	int n,i;
	long int sum = 0;
	scanf("%d",&n);
	long int a[n],b[n];
	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
	for(i=0;i<n;i++)
		scanf("%ld",&b[i]);
	sort(a,n);
	sort(b,n);
	for(i=0;i<n;i++)
		sum += a[i] * b[i];
	printf("%ld",sum);
	return 0;
}

