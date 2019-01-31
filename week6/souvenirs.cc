#include<iostream>
#include<iomanip>
#include<stdlib.h>


using namespace std;

void sort(int *value,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
			if(value[j] > value[i])
			{
				temp = value[i];
				value[i] = value[j];
				value[j] = temp;
			}
	}
	/*
	cout<<"\nTo display the sorted matrix\n";
	for(i=0;i<n;i++)
		cout<<value[i]<<setw(5);
	cout<<"\n";
	*/
}

int knapsack(int *value,int n,int sum)
{
	int i,s,j,k;
	int dp[n+1][sum+1];
	int temp;
	int split_possible = 0;

	for(i=0;i<=n;i++)
		dp[i][0] = 0;
	for(s=0;s<=sum;s++)
		dp[0][s] = 0;
	for(i=1;i<=n;i++)
	{
		for(s=1;s<=sum;s++)
		{
			dp[i][s] = dp[i-1][s];
			if(s >= value[i-1])
			{
				temp = dp[i-1][s-value[i-1]] + value[i-1];
				if(temp > dp[i][s] && temp <= s)
				{
					dp[i][s] = temp;
				}
			}
		}
	}
	temp =0;
	for(i=0;i<=n;i++)
	{
		if(dp[i][sum] == sum)
		{
			temp = 1;
			split_possible = 1;
			j = sum;
			break;
		}
	}
	/*
	cout<<"\nTo display the knapsack matrix\n";
	for(k=0;k<=n;k++)
	{
		cout<<"\n";
		for(s=0;s<=sum;s++)
			cout<<dp[k][s]<<setw(5);
	}
	cout<<"\n";
	*/
	if(temp == 1)
	{
//		cout<<"\nTo display the group found\n";
		while(i >= 1 && j >= 1)
		{
			if(dp[i][j] == dp[i-1][j])
				i = i -1;
			else
			{
				j = j - value[i-1];
//				cout<<value[i-1]<<setw(5);
				value[i-1] = 0;
				i = i - 1;
			}
		}
	}
	else
		split_possible = 0;
	/*
	cout<<"\nTo display the modified value matrix\n";
	for(i=0;i<n;i++)
		cout<<value[i]<<setw(5);
	cout<<"\n\n";
	*/
	return split_possible;
}

int partitioning(int *value,int n)
{
	int i,j;
	int split_possible = 0;
	int sum = 0;
	int groups = 0;
	for(i=0;i<n;i++)
		sum += value[i];
	if(sum%3 == 0)
	{
		sort(value,n);
		sum = sum / 3;
		split_possible = 1;
		while(split_possible)
		{
			if(!knapsack(value,n,sum))
			{
				split_possible = 0;
				break;
			}
			else
			{
				groups++;
			}
		}
	}
	else
		split_possible = 0;
	if(groups == 3)
		split_possible = 1;
	return split_possible;
}

int main()
{
	int n;
	cin>>n;
	int *value = (int *)malloc(sizeof(int) * n);
	for(int i = 0;i<n;i++)
		cin>>value[i];	
	int split_possible = partitioning(value,n);
	cout<<split_possible;
	return 0;
}
