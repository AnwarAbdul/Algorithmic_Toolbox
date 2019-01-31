#include<iostream>


using namespace std;

int primitive_calculator(int *predecessor,int n)
{
	int operations_count[n+1];
	operations_count[0] = operations_count[1] = 0;
	predecessor[0] = 0;
	predecessor[1] = 1;
	int i;
	for(i=2;i<=n;i++)
	{
		operations_count[i] = operations_count[i-1] + 1;
		predecessor[i] = i - 1;
		if(i %3 == 0)
		{
			if(operations_count[i/3] < operations_count[i])
			{
				operations_count[i] = operations_count[i/3] + 1;
				predecessor[i] = i/3;
				continue;
			}
		}
		if(i % 2 == 0)
		{
			if(operations_count[i/2] < operations_count[i])
			{
				operations_count[i] = operations_count[i/2] + 1;
				predecessor[i] = i/2;
				continue;
			}
		}
	}
	return operations_count[n];
}

int main()
{
	int n;
	cin>>n;
	int predecessor[n+1];
	int operations_count;
	int i;int j=0;
	i= n;
	operations_count = primitive_calculator(predecessor,n);
	int a[operations_count + 1];
	a[0] = n;
	while(i > 1)
	{
		i = predecessor[i];
		a[++j] = i;
	}
	cout<<operations_count<<"\n";
	for(i=0;i<=j;i++)
		cout<<a[j-i]<<" ";

	return 0;
}

