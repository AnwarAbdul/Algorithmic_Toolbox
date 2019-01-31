#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include<stdlib.h>

using namespace std;

int sum(int a,int b)
{
	return a+b;
}
int product(int a,int b)
{
	return a*b;
}
int sub(int a,int b)
{
	return a-b;
}
int Min_check(int a,int b,int c,int d,int min)
{
	if(a < min)
		min = a;
        if(b < min)
		min = b;
	if(c < min)
		min = c;
	if(d < min)
		min = d;
	return min;	
}
int Max_check(int a,int b,int c,int d,int max)
{
	if(a > max)
		max = a;
	if(b > max)
		max = b;
	if(c > max)
		max = c;
	if(d > max)
		max = d;
	return max;
}
void MinAndMax(int **m,int **M,char *op,int i,int j,int *min,int *max)
{
	int k;
	int a,b,c,d;
	for(k=i;k<=j-1;k++)
	{
		if(op[k] == '+')
		{
			a = sum(m[i][k],m[k+1][j]);
			b = sum(m[i][k],M[k+1][j]);
			c = sum(M[i][k],M[k+1][j]);
			d = sum(M[i][k],m[k+1][j]);
		}
		else if(op[k] == '*')
		{
			a = product(m[i][k],m[k+1][j]);
			b = product(m[i][k],M[k+1][j]);
			c = product(M[i][k],M[k+1][j]);
			d = product(M[i][k],m[k+1][j]);
		}
		else
		{
			a = sub(m[i][k],m[k+1][j]);
			b = sub(m[i][k],M[k+1][j]);
			c = sub(M[i][k],M[k+1][j]);
			d = sub(M[i][k],m[k+1][j]);
		}
	*min = Min_check(a,b,c,d,*min);
	*max = Max_check(a,b,c,d,*max);

	}
}

int parentheses(int *a,char *op,int num_n,int op_n)
{
	int **M = (int **)malloc(sizeof(int *) * num_n);
	int **m = (int **)malloc(sizeof(int *) * num_n);
	int i;
	for(i=0;i<num_n;i++)
	{
		M[i] = (int *)malloc(sizeof(int) * num_n);
		m[i] = (int *)malloc(sizeof(int) * num_n);
	}
	int j;
	for(i=0;i<num_n;i++)
	{
		for(j=0;j<num_n;j++)
		{
			if(i==j)
			{
				m[i][j] = a[i];
				M[i][j] = a[i];
			}
			else
			{
				m[i][j] = 0;
				M[i][j] = 0;
			}
		}
	}
	/*
	cout<<"\n";
	for(i=0;i<num_n;i++)
	{
		cout<<"\n";
		for(j=0;j<num_n;j++)
			cout<<M[i][j]<<" ";
	}
	cout<<"\n";
	*/
	int s;
	int *min,*max;
	min = (int *)malloc(sizeof(int));
	max = (int *)malloc(sizeof(int));
	for(s=1;s<num_n;s++)
	{
		for(i=0;i<num_n-s;i++)
		{
			*min = 1000;
			*max = -1000;
			j = i+s;
			MinAndMax(m,M,op,i,j,min,max);
			m[i][j] = *min;
			M[i][j] = *max;
		}
	}
	for(i=0;i<num_n;i++)
	{
		cout<<"\n";
		for(j=0;j<num_n;j++)
			cout<<M[i][j]<<" ";
	}
	cout<<"\n";
	return M[0][num_n-1];
}

int main()
{
	string expression;
	cin>>expression;
	int total_length = expression.length();
	int op_n = (total_length - 1)/2;
	int num_n = total_length - op_n;
	int a[num_n];
	char s[total_length+1];
	char op[op_n+1];
	strcpy(s,expression.c_str());
	int i;
	for(i=0;i<total_length;i++)
	{
		if(i%2 ==0)
			a[i/2] = s[i] - 48;
		else
			op[i/2] = s[i];
	}
	int value = parentheses(a,op,num_n,op_n);
	/*
	cout<<"\n";
	for(i=0;i<num_n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	for(i=0;i<op_n;i++)
		cout<<op[i]<<" ";
	cout<<"\n";
	*/
	cout<<value;
	return 0;
}
