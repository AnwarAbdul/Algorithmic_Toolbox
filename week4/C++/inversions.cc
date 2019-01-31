#include<iostream>

using namespace std;

int count;

void merge(int *a,int l,int n,int *count)
{
	int b[n/2];
	int c[n-n/2];
	int temp = 0;
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
		if(b[i] <= c[j])
		{
			//cout<<"\nhit for "<<b[i]<<" from left partition";
			//cout<<"\ncount value prior to hit = "<<*count<<" temp = "<<temp;
			if(temp != b[i])
			{
				*count = *count + j;
				temp = b[i];
			}
			//cout<<"\ncount value after hit = "<<*count;
			a[k] = b[i];
			i++;
			k++;
			
		}
		else
		{
			//cout<<"\nhit for "<<b[i]<<" & "<<c[j];
			a[k] = c[j];
			j++;
			k++;
			//cout<<"\ncount value prior to hit = "<<*count<<" temp = "<<temp;
			if(temp != b[i])
				{
					*count = *count + j;
					temp = b[i];
				}
			else
				*count = *count + 1;	
			//cout<<"\ncount value after hit = "<<*count;
		}
	}
	if(i < (n/2-1))
		{
			//cout<<"\n\nhit for remainder items "<<"l = "<<l<<" n = "<<n;
			//cout<<"\ncount value prior to hit = "<<*count;
			*count = *count + (n/2 - i - 1)*j;
			//cout<<"\ncount value after hit = "<<*count<<"\n"	;
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

void merge_sort(int *a,int l,int n,int *count)
{
	if(n == 1)
		return;
	else
	{
		merge_sort(a,l,n/2,count);
		merge_sort(a,l+n/2,n-n/2,count);
		merge(a,l,n,count);
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
	int count;
	count = 0;
	merge_sort(a,0,n,&count);
	/*
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	*/
	//cout<<"\n";
	cout<<count;
	return 0;
}