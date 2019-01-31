#include<iostream>
#include<stdlib.h>

using namespace std;

int money_change(int money,int *a,int n)
{
	int coin_count[money+1];
	coin_count[0] = 0;
	int m,i,num;
	int max = 1000;
	for(m=1;m<=money;m++)
	{
		coin_count[m] = max;
		for(i=0;i<n;i++)
		{
			if(m >= a[i])
			{
				num = coin_count[m-a[i]] + 1;
				if( num < coin_count[m])
					coin_count[m] = num;
			}
		}
	}
	return coin_count[money];

}

int main()
{
	int coin_denominations[] = {1,3,4};
	int money;
	cin>>money;
	int coin_count = money_change(money,coin_denominations,sizeof(coin_denominations)/sizeof(int));
	cout<<coin_count;
	return 0;
}

