#include<iostream>
#include<iomanip>

using namespace std;


int mult(int a, int b)
{
	return a*b;
}

int add(int a,int b)
{
	return a+b;
}

int sub(int a,int b)
{
	return a-b;
}

int find_min(int min,int a,int b,int c,int d)
{
	int lowest = min;
	if(a < lowest)
	{
		lowest = a;
	}
	if(b < lowest)
	{
		lowest = b;
	}
	if(c < lowest)
	{
		lowest = c;
	}
	if(d < lowest)
	{
		lowest = d;
	}
	return lowest;
}

int find_max(int max,int a,int b,int c,int d)
{
	int highest = max;
	if(a > highest)
	{
		highest = a;
	}
	if(b > highest)
	{
		highest = b;
	}
	if(c > highest)
	{
		highest = c;
	}
	if(d > highest)
	{
		highest = d;
	}
	return highest;
}


void MinAndMax(char *op,int i,int j,int **m,int **M,int *min,int *max,int n)
{
//	cout<<"At top of MinAndMax"<<" *min = "<<*min<<" *max = "<<*max<<" i = "<<i<<" j = "<<j<<"\n";
	int k;
	int a,b,c,d;
	int i1,i2;


	for(k=i;k<=j-1;k++)
	{
//		cout<<"k = "<<k<<" op[k] = "<<op[k]<<"\n";
		if(op[k] == '*')
		{
			a = mult(m[i][k],m[k+1][j]);
			b = mult(m[i][k],M[k+1][j]);
			c = mult(M[i][k],m[k+1][j]);
			d = mult(M[i][k],M[k+1][j]);
		}
		else if(op[k] == '+')
		{
			a = add(m[i][k],m[k+1][j]);
			b = add(m[i][k],M[k+1][j]);
			c = add(M[i][k],m[k+1][j]);
			d = add(M[i][k],M[k+1][j]);
		}
		else
		{
			a = sub(m[i][k],m[k+1][j]);
			b = sub(m[i][k],M[k+1][j]);
			c = sub(M[i][k],m[k+1][j]);
			d = sub(M[i][k],M[k+1][j]);
		}
//		cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<" d = "<<d;
		*min = find_min(*min,a,b,c,d);
		*max = find_max(*max,a,b,c,d);
	}

}


int parentheses(int *d,char *op,int n)
{
	int **m = (int **)malloc(sizeof(int *) * n);
	int **M = (int **)malloc(sizeof(int *) * n);
	int s,i,j;
	for(i=0;i<n;i++)
	{
		m[i] = (int *)malloc(sizeof(int) * n);
		M[i] = (int *)malloc(sizeof(int) * n);
	}
	int *min = (int *)malloc(sizeof(int));
	int *max = (int *)malloc(sizeof(int));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i == j)
			{
				m[i][i] = d[i];
				M[i][i] = d[i];
			}
			else
			{
				m[i][j] = 0;
				M[i][j] = 0;
			}
		}
	}
	/*
	cout<<"\nDiplaying the inited max matrix\n";
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<n;j++)
			cout<<M[i][j]<<setw(5);
	}
	cout<<"\n";
	*/
	for(s=1;s<n;s++)
	{
		for(i=0;i<n-s;i++)
		{
			j = i + s;
			*min = 1000;
			*max = -1000;
			
			MinAndMax(op,i,j,m,M,min,max,n);
			m[i][j] = *min;
			M[i][j] = *max;
	//		cout<<"m["<<i<<"]["<<j<<"] = "<<*min<<" ";
	//		cout<<"M["<<i<<"]["<<j<<"] = "<<*max<<" ";
	//		cout<<"\n"<<"\n";
		}
	}
	
	cout<<"\nDiplaying the final max matrix\n";
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<n;j++)
			cout<<M[i][j]<<setw(5);
	}
	cout<<"\n";
	cout<<"\nDiplaying the final min matrix\n";
	for(i=0;i<n;i++)
	{
		cout<<"\n";
		for(j=0;j<n;j++)
			cout<<m[i][j]<<setw(5);
	}
	cout<<"\n";
	
	return M[0][n-1];
}

int main()
{
	//Expression is  5 - 8 + 7 * 4 - 8 + 9
	int d[] = {5,8,7,4,8,9};
	char op[] = {'-','+','*','-','+'};
	int n = sizeof(d)/sizeof(int);
	int max_value = parentheses(d,op,n);
	cout<<max_value;
	return 0;
}
