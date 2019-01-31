#include<iostream>


using namespace std;


int binary_search(int *a,int low,int high,int key)
{
	int mid = low + (high-low)/2;
	if(low > high)
		return low;
	else if(a[mid] == key)
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
	int n1;
	cin>>n1;
	int b[n1];
	for(i=0;i<n1;i++)
		cin>>b[i];
	for(i=0;i<n1;i++)
		cout<<binary_search(a,0,n-1,b[i])<<" ";
	return 0;
	
}