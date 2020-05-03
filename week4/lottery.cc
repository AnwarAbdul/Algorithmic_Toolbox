#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;


int binary_search(int *a,int low,int high,int key)
{
	int mid = low + (high-low)/2;
	if(low > high)
		return low;
	else if(key == a[mid])
		return mid;
	else if(key > a[mid])
		return binary_search(a,mid+1,high,key);
	else
		return binary_search(a,low,mid-1,key);
}

int partition(int *a,int l, int r)
{
	int i,j;
	j = l;
	int pivot,temp;
	pivot = a[l];
	for(i=l+1;i<=r;i++)
		{
			if(pivot > a[i])
			{
				j++;
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}			
		}
		temp = a[l];
		a[l] = a[j];
		a[j] = temp;
	return j;		
}


void quick_sort(int *a,int l, int r)
{
	int m,temp;
	while(l < r)
	{
		srand(time(NULL));
		int random_pos = rand() %(r-l) + l;
		temp = a[l];
		a[l] = a[random_pos];
		a[random_pos] = temp;
		m = partition(a,l,r);
		if((m-l) < (r-m))
		{
			quick_sort(a,l,m-1);
			l = m+1;
		}
		else
		{	
			quick_sort(a,m+1,r);
			r = m - 1;
		}
	}
}

int main()
{
	int ns;
	cin>>ns;
	int np;
	cin>>np;
	int i;
	int a[2*ns];
	for(i=0;i<(2*ns);i++)
		cin>>a[i];
	
	int left_points[ns];int right_points[ns];
	for(i=0;i<(2*ns);i++)
	{
		if(i%2 == 0)
			left_points[i/2] = a[i];
		else
			right_points[i/2] = a[i];
	}
	quick_sort(left_points,0,ns-1);
	quick_sort(right_points,0,ns-1);
	
	int b[np];
	for(i=0;i<np;i++)
		cin>>b[i];

	int indexl,indexr,num,indexr_help;
	for(i=0;i<np;i++)
	{
		indexl = binary_search(left_points,0,ns-1,b[i]);
		indexr = binary_search(right_points,0,ns-1,b[i]);
		
		while(left_points[indexl] == b[i])
		{
			indexl++;
		}
		indexr_help = indexr;
		while(right_points[indexr] == b[i])
		{
			indexr--;
		}
		if(indexr_help != indexr)
			indexr++;
		num = indexl - indexr;
		cout<<num<<" ";
	}
	
	return 0;
}
