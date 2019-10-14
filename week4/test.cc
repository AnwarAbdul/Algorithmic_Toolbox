#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


void partition(int *a,int l,int r,int *m1.int *m2)
{
	int temp,i,j,pivot;
	pivot = a[l];
	i = l+1;
	j = l;
	if( (r-l) == 1)
	{
		if(a[l] > a[r])
		{
			temp = a[l];
			a[l] = a[r];
			a[r] = temp;
		}
		*m1 = l;
		*m2 = r;
		return;
	}
	else
	{
		while(i <= r)
		{
			if(pivot > a[i])
			{
				j++;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				i++;
			}
			else if(pivot == a[i])
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
		return;
	}
}

void qsort(int *a,int l,int r)
{
	if(l >= r)
		return;
	else
	{
		int m1,m2,swap,random_pos;
		srand(time(NULL));
		random_pos = rand() % (r-l) + l;
		swap  = a[random_pos];
		a[random_pos] = a[l];
		a[l] = swap;
		partition(a,l,r,&m1,&m2);
		qsort(a,l,m1);
		qsort(a,m2,r);
	}
}


int main()
{
	int n;
	cin>>n;
	int a[n],i;
	for(i = 0;i < n; i++)
		cin>>a[i];
	qsort(a,0,n-1);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}