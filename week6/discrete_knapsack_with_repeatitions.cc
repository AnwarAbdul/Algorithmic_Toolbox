#include<iostream>


using namespace std;


int knapsack(int *value,int *weight, int *item_value, int n,int W)
{
	value[0] = 0;
	int i,w;
	int val;
	for(w=1;w<=W;w++)
	{
		value[w] = 0;
		for(i=0;i<n;i++)
		{
			if(weight[i] <= w)
			{	
				val = value[w-weight[i]] + item_value[i];
				if( val > value[w])
					value[w] = val;
			}

		}
	}
	/*
	cout<<"Printing all the max_values per weight\n";
	for(i=0;i<=W;i++)
		cout<<"value["<<i<<"] = "<<value[i]<<"\n";
	cout<<"\n";
	*/
	return value[W];

}

int main()
{
	int W;
	cin>>W;
	int n;
	cout<<"Enter the number of items haveing weights/values\n";
	cin>>n;
	int item_value[n];int weight[n];
	cout<<"Enter the weights\n";
	int i;
	for(i=0;i<n;i++)
		cin>>weight[i];
	cout<<"\n";
	cout<<"Enter the values\n";
	for(i=0;i<n;i++)
		cin>>item_value[i];
	cout<<"\n";
	/*
	cout<<"Displaying the entered values\n";
	for(i=0;i<n;i++)
		cout<<item_value[i]<<" ";
	cout<<"\n";
	for(i=0;i<n;i++)
		cout<<weight[i]<<" ";
	cout<<"\n";
	*/
	int value[W+1];
	int max_value;
	max_value = knapsack(value,weight,item_value,n,W);
	cout<<max_value;
	return 0;
}
