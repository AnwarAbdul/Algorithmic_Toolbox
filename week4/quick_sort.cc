#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void partition3(int *a, int l, int r,int *m1,int *m2)
{
	int i,j,temp,x;
	x = a[l];
	j = l;
	i = l + 1;
	if((r-l) == 1)
	{
		if(a[l] > a[r])
		{
			temp = a[l];
			a[l] = a[r];
			a[r] = temp;
		}
		*m1 = l;
		*m2 = r;
	}
	while(i<=r)
	{
		if(x > a[i])
		{
			j++;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			i++;
		}
		else if(x == a[i])
			i++;
		else
		{
			temp = a[r];
			a[r] = a[i];
			a[i] = temp;
			r--;
		}
	}
	temp = a[l];
	a[l] = a[j];
	a[j] = temp;
	*m1 = j-1;
	*m2 = i;	
}

void quick_sort(int *a,int l, int r)
{
	int temp,rx,m1,m2;
	srand(time(NULL));
	if(l >= r)
		return;
	else
	{
		rx = rand() % (r-l) + l;
		temp = a[rx];
		a[rx] = a[l];
		a[l] = temp;
		partition3(a,l,r,&m1,&m2);
		quick_sort(a,l,m1);
		quick_sort(a,m2,r);
	}
}

int main()
{
	int n;
	cin>>n;
	int a[n],i;
	for(i=0;i<n;i++)
		cin>>a[i];
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}

