#include<iostream>
#include<iomanip>

using namespace std;

int gold_knapsack(int *bar_weight,int W,int n)
{
	int **weight_array = (int **)malloc(sizeof(int *) * (n+1));
	int i,w;
	for(i=0;i<(n+1);i++)
		weight_array[i] = (int *)malloc(sizeof(int *) * (W+1));
	int temp;
	for(i=0;i<=n;i++)
		weight_array[i][0] = 0;
	for(w=0;w<=W;w++)
		weight_array[0][w] = 0;
	for(i=1;i<=n;i++)
	{
		for(w=1;w<=W;w++)
		{
			weight_array[i][w] = weight_array[i-1][w];
			if(bar_weight[i-1] <= W )
			{
				temp = weight_array[i-1][w-bar_weight[i-1]] + bar_weight[i-1];
				if((temp > weight_array[i][w] && temp <= w))
					weight_array[i][w] = temp;
			}
		}
	}
	/*
	cout<<"\nDisplaying the gold_knapsack matrix\n";
	for(i=0;i<=n;i++)
	{
		cout<<"\n";
		for(w=0;w<=W;w++)
			cout<<weight_array[i][w]<<setw(5);
	}
	cout<<"\n";
	*/
	return weight_array[n][W];
}

int main()
{
	int W;
	cin>>W;
	int n;
	cin>>n;
	int *bar_weight = (int *)malloc(sizeof(int) * n);
	int i;
	for(i=0;i<n;i++)
		cin>>bar_weight[i];
	int max_weight;
	max_weight = gold_knapsack(bar_weight,W,n);
	cout<<max_weight;
	return 0;
}
