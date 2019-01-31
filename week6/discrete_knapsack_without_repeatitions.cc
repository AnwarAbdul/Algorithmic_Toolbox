#include<iostream>
#include<iomanip>

using namespace std;


int knapsack(int *weight,int *item_value,int n,int W)
{
	int i,w;
	int val;
	int value[n+1][W+1];
	for(i=0;i<=n;i++)
		value[i][0] = 0;
	for(w=0;w<=W;w++)
		value[0][w] = 0;
	for(i=1;i<=n;i++)
	{
		for(w=1;w<=W;w++)
		{
			value[i][w] = value[i-1][w];
			if(weight[i-1] <= w)
			{
				val = value[i-1][w-weight[i-1]] + item_value[i-1];
				if(val > value[i][w])
					value[i][w] = val;
			}
		}
	}
	cout<<"Displaying the matrix of the knapsack function\n";
	for(i=0;i<=n;i++)
	{
		cout<<"\n";
		for(w=0;w<=W;w++)
		{
			cout<<value[i][w]<<setw(5);
		}

	}
	cout<<"\n";
	return value[n][W];
}			

int main()
{
	int W;
	cin>>W;
	int n;
	cout<<"Enter the number of items having weights/values\n";
	cin>>n;
	int i;
	int weight[n],item_value[n];
	cout<<"Enter the weights\n";
	for(i=0;i<n;i++)
		cin>>weight[i];
	cout<<"Enter the values\n";
	for(i=0;i<n;i++)
		cin>>item_value[i];
	int max_value;
	max_value = knapsack(weight,item_value,n,W);
	cout<<max_value;
	return 0;
}
