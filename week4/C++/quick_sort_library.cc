#include"quick_sort_header.h"


using namespace std;


void partition(int *a,int l, int r, int *m1, int *m2)
{
	int pivot,temp,i,j;
	j = l;
	i = l+1;
	pivot = a[l];
	if((r-l) == 1)
	{
		if(a[l] > a[r])
		{
			temp = a[l];
			a[l] = a[r];
			a[r] = temp;
			*m1 = l;
			*m2 = r;
		}
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
				temp = a[i];
				a[i] = a[r];
				a[r] = temp;
				r--;
			}
		}
		temp = a[l];
		a[l] = a[j];
		a[j] = temp;
		*m1 = j - 1;
		*m2 = i;		
	}
	
}

void quick_sort(int *a, int l, int r)
{
	int m1,m2;
	int temp;
	int random_pos;
	if(l >= r)
		return;
	else
	{
		srand(time(NULL));
		random_pos = rand() % (r-l) + l;
		temp = a[l];
		a[l] = a[random_pos];
		a[random_pos] = temp;
		partition(a,l,r,&m1,&m2);
		quick_sort(a,l,m1);
		quick_sort(a,m2,r);
	}
}