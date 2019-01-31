#include<iostream>

using namespace std;

int binary_search(int *a,int low,int high,int key)
{
	if(low>high)
		return -1;
	int mid;
	mid = low + (high-low)/2;
	if(key == a[mid])
		return mid;
	else if(key > a[mid])
		return binary_search(a,mid+1,high,key);
	else
		return binary_search(a,low,mid-1,key);
}


int main()
{
	int n;
	cin>>n;
	int a[n];
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	int k;
	cin>>k;
	int b[k];
	for(i=0;i<k;i++)
		cin>>b[i];
	for(i=0;i<k;i++)
		cout<<binary_search(a,0,n-1,b[i])<<" ";
	return 0;
}
