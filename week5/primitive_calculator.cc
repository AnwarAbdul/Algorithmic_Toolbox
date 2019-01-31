#include<iostream>


using namespace std;


int base_number_generator(int *b,int n)
{
	int i=1;int operations = 0;
	while(i != n)
	{
		b[operations] =i;
		if(n==8)
		{
			i = i*2;
		}
		else if((i*3) <= n)
			i = i*3;
		else if((i*2) <= n)
			i = i * 2;
		else
			i = i +1;
		++operations;
	}
	return operations;
}


int main()
{
	int n;
	cin>>n;
	int operations=0;
	int base_number_operations;
	int a[n+1];
	int i;int j =0;int k =0;
	int b[10];
	a[0] = n;
	while(n>1)
	{
		if(n <= 10)
		{
			j = ++operations;
			base_number_operations = base_number_generator(b,n);
			operations += base_number_operations;
			for(i = j,k=base_number_operations-1;i < operations;i++,k--)
				a[i] = b[k];
			break;
		}
		if(n%3 ==0)
			n = n / 3;
		else if(n%2 ==0)
			n = n / 2;
		else
			n = n-1;
		a[++operations] = n;
	}
	if( n!= 1)
	{	
		cout<<operations-1<<"\n";
		for(i=0;i<operations;i++)
			cout<<a[operations - 1 -i]<<" ";

	}
	else
	{
		cout<<operations<<"\n";
		cout<<a[0]<<" ";
	}

	return 0;
}
