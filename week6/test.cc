#include<iostream>


using namespace std;

void display(int **a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<n;j++)
			cout<<a[i][j]<<" ";
	}
}

int main()
{
	cout<<"Testing....\n";
	int n = 3;
	int i,j;
	int **a = (int **)malloc(sizeof(int *) * n);
	for(i=0;i<n;i++)
		a[i] = (int *)malloc(sizeof(int) * n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j] = (i+1)*(j+1);
	display(a,n);
	cout<<"\nsize of long long int = "<<sizeof(long long int)<<"\n";
	return 0;
}
