#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<math.h>

using namespace std;


long long int mult(long long int a,long long int b)
{
	return a*b;
}

long long int add(long long int a,long long int b)
{
	return a+b;
}

long long int sub(long long int a,long long int b)
{
	return a-b;
}

int find_min(long long int min,long long int a,long long int b,long long int c,long long int d)
{
	long long int lowest = min;
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

long long int find_max(long long int max,long long int a,long long int b,long long int c,long long int d)
{
	long long int highest = max;
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


void MinAndMax(char *op,int i,int j,long long int **m,long long int **M,long long int *min,long long int *max,int n)
{
//	cout<<"At top of MinAndMax"<<" *min = "<<*min<<" *max = "<<*max<<" i = "<<i<<" j = "<<j<<"\n";
	int k;
	long long int a,b,c,d;
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


long long int parentheses(long long int *d,char *op,int n)
{
	long long int **m = (long long int **)malloc(sizeof(long long int *) * n);
	long long int **M = (long long int **)malloc(sizeof(long long int *) * n);
	int s,i,j;
	for(i=0;i<n;i++)
	{
		m[i] = (long long int *)malloc(sizeof(long long int) * n);
		M[i] = (long long int *)malloc(sizeof(long long int) * n);
	}
	long long int *min = (long long int *)malloc(sizeof(long long int));
	long long int *max = (long long int *)malloc(sizeof(long long int));
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
			*min = 205891132094650;
			*max = -205891132094650;
	
	//		cout<<"\n*min = "<<*min<<"\n";
	//		cout<<"\n*max = "<<*max<<"\n";

			MinAndMax(op,i,j,m,M,min,max,n);
			m[i][j] = *min;
			M[i][j] = *max;
	//		cout<<"m["<<i<<"]["<<j<<"] = "<<*min<<" ";
	//		cout<<"M["<<i<<"]["<<j<<"] = "<<*max<<" ";
	//		cout<<"\n"<<"\n";
		}
	}
	/*
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
	*/
	return M[0][n-1];
}

int main()
{
	//Expression is  5 - 8 + 7 * 4 - 8 + 9
	string str;
	getline(cin,str);
	int N = str.length();
	//cout<<"\nN = "<<N<<"\n";
	int nop = (N-1)/2;
	int n = nop+1;
	long long int d[n];
	int i;
	char op[n-1];
	char temp[N+1];
	strcpy(temp,str.c_str());
	for(i=1;i<N-1;i=i+2)
		op[i/2] = temp[i];
	for(i=0;i<N;i=i+2)
		d[i/2] = temp[i] - 48;
/*
	cout<<"\nPrinting obtained op[] and d[] matrices\n";
	cout<<"n = "<<n<<"\n";
	for(i=0;i<n;i++)
		cout<<d[i]<<setw(5);
	cout<<"\n";
	for(i=0;i<n-1;i++)
		cout<<op[i]<<" ";
	cout<<"\n";
*/
	long long int max_value = parentheses(d,op,n);
	cout<<max_value;
	return 0;
}
