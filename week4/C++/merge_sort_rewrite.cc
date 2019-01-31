#include<iostream>

using namespace std;


void merge(int *a,int l,int n)
{
	int b[n/2];
	int c[n-n/2];
	int i,j,k;
	for(i=l;i<(l+n/2);i++)
		b[i-l] = a[i];
	for(j=l+n/2;j<l+n;j++)
		c[j-(l+n/2)] = a[j];
	i = 0;
	j = 0;
	k = l;
	while((i < n/2) && (j < (n-n/2)))
	{
		if(b[i] < c[j])
		{
			a[k] = b[i];
			i++;
			k++;
		}
		else
		{
			a[k] = c[j];
			j++;
			k++;
		}
	}
	while(i < n/2)
	{
		a[k] = b[i];
		k++;
		i++;
	}
	while(j < (n-n/2))
	{
		a[k] = c[j];
		k++;
		j++;
	}
}

void merge_sort(int *a,int l,int n)
{
	if(n == 1)
		return;
	else
	{
		merge_sort(a,l,n/2);
		merge_sort(a,l+n/2,n-n/2);
		merge(a,l,n);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];

	merge_sort(a,0,n);
	cout<<"\nTo display sorted matrix\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}