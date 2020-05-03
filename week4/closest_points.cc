#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
#include<cfloat>


using namespace std;


void partition(long long int *a,long long int *b,int l,int r,int *m1,int *m2)
{
	long long int temp,pivot;
	int i,j;
	j = l;
	i = l + 1;
	pivot = a[l];
	if(r - l  == 1 )
	{
		if(a[l] > a[r])
		{
			temp = a[l];
			a[l] = a[r];
			a[r] = temp;
			temp = b[l];
			b[l] = b[r];
			b[r] = temp;
		}
		*m1 = l;
		*m2 = r;
	}
	else
	{
		while( i <= r)
		{
			if(pivot > a[i])
			{
				j++;
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
				temp = b[j];
				b[j] = b[i];
				b[i] = temp;
				i++;
			}
			else if(pivot == a[i])
				i++;
			else
			{
				temp = a[r];
				a[r] = a[i];
				a[i] = temp;
				temp = b[r];
				b[r] = b[i];
				b[i] = temp;
				r--;
			}
		}
		temp = a[l];
		a[l] = a[j];
		a[j] = temp;
		temp = b[l];
		b[l] = b[j];
		b[j] = temp;
		*m1 = j-1;
		*m2 = i;
	}
	
}

void qsort(long long int *a,long long int *b,int l,int r)
{
	long long int temp;
	int random_pos,m1,m2;
	if(l >= r)
		return;
	else
	{
		srand(time(NULL));
		random_pos = rand() % (r-l) + l;
		temp = a[random_pos];
		a[random_pos] = a[l];
		a[l] = temp;
		temp = b[random_pos];
		b[random_pos] = b[l];
		b[l] = temp;
		partition(a,b,l,r,&m1,&m2);
		qsort(a,b,l,m1);
		qsort(a,b,m2,r);
	}
}

long double divide_and_combine(long long int *x,long long int *y,int l,int n)
{
	if(n == 1)
		return DBL_MAX;
	else if(n == 2)
		return sqrt(abs(x[l]-x[l+1]) * abs(x[l]-x[l+1]) + abs(y[l]-y[l+1]) * abs(y[l]-y[l+1]));
	else
	{
		//long long int xl[n],yl[n],xr[n],yr[n];
		int i,j,n_strip;

		//int ll,rr;
		//ll = 0;rr = 0;
		/*
		for(i=0;i<n;i++)
		{
			if(x_aux[i] <= x[l+n/2])
			{
				xl[ll] = x_aux[i];
				yl[ll] = y_aux[i];
				ll++;
			}
			else
			{
				xr[rr] = x_aux[i];
				yr[rr] = y_aux[i];
				rr++;
			}
		}
	*/
		long double d1,d2;
		/*
		d1 = divide_and_combine(x,y,l,n/2,xl,yl);
		if(rr == 0)
			d2 = divide_and_combine(x,y,l+n/2,n-n/2,xl,yl);
		else
			d2 = divide_and_combine(x,y,l+n/2,n-n/2,xr,yr);
		*/
		long long int x_copy[n],y_copy[n];
		long double d,temp,dx;

		d1 = divide_and_combine(x,y,l,n/2);
		d2 = divide_and_combine(x,y,l+n/2,n-n/2);
		d = d1;
	
		if(d2 < d)
			d = d2;
		
		dx = d;

		j = 0;
		for(i=l;i<(l+n);i++)
		{
			if((abs(x[i] - x[l+n/2]) <= d))
			{	
				x_copy[j] = x[i];
				y_copy[j] = y[i];
				j++;
			}
		}
		n_strip = j;
		
		

		qsort(y_copy,x_copy,0,n_strip-1);
		

		for(i = 0; i < n_strip; i++)
		{
			for(j = i+1; (j < n_strip) && (j <= i+7); j++ )
			{
				temp = sqrt(abs(x_copy[i]-x_copy[j]) * abs(x_copy[i]-x_copy[j]) + abs(y_copy[i]-y_copy[j]) * abs(y_copy[i]-y_copy[j]));
				if(temp < d)
					d = temp;
			}	
		}
		return d;
	}
}


int main()
{
	int n;
	cin>>n;
	long long int x[n],y[n],x_copy[n],y_copy[n];
	int i;
	long double min_distance;

	

	for(i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	
	
	
	qsort(x,y,0,n-1);
	//qsort(y_copy,x_copy,0,n-1);
	
	min_distance = divide_and_combine(x,y,0,n);		
	
	cout<<fixed;
	cout<<setprecision(4);
	cout<<min_distance<<"\n";
	return 0;
}





