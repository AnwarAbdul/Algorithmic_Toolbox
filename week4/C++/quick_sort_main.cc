#include"quick_sort_header.h"
#include<iomanip>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int i;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	quick_sort(a,0,n-1);
	cout<<"\nTo display sorted matrix\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}