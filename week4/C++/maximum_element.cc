#include<iostream>


using namespace std;

int maximum_element(int *a,int l,int n)
{
	int lmax,rmax,countl,countr,i;
	if(n==1)
		return a[l];
	else if(n==2)
	{
		if(a[l] == a[l+1])
			return a[l];
		else
			return -1;
	}
	else
	{
//		cout<<"l = "<<l<<" n = "<<n/2<<"\n";
//		cout<<"l = "<<l+n/2<<" n = "<<n-n/2<<"\n";
		lmax = maximum_element(a,l,n/2);
		rmax = maximum_element(a,l+n/2,n-n/2);
//		cout<<" lmax = "<<lmax<<"\n";
//		cout<<" rmax = "<<rmax<<"\n";
		if((lmax == -1) && (rmax == -1))
			return -1;
		else if(lmax == rmax)
			return lmax;
		else
		{
			countl = countr =0;
			if(lmax != -1)
			{
				for(i=l;i<l+n;i++)
				{
					if(a[i] == lmax)
						countl++;
				}
			}
			if(rmax != -1)
			{	
				for(i=l;i<l+n;i++)
				{
					if(a[i] == rmax)
						countr++;
				}
			}
//			cout<<"countl = "<<countl<<"\n";
//			cout<<"countr = "<<countr<<"\n";
			if(countl > n/2)
				return lmax;
			else if(countr > n/2)
				return rmax;
			else
				return -1;

		}
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
	int x = maximum_element(a,0,n);
//	cout<<"x = "<<x<<"\n";
	if(x != -1)
		cout<<1;
	else
		cout<<0;
	return 0;
}
