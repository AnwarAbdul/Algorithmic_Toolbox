#include<stdio.h>
#include<stdlib.h>

int *polynomial_mult(int *a,int *b,int al,int bl,int n)
{
	int i;
	int *r = (int *) malloc(sizeof(int) * (2*n-1));
	for(i=0;i<(2*n-1);i++)
		r[i] = 0;
	int *r1,*r2,*r3,*r4;
	if(n==1)
	{
		r[0]= a[al] * b[bl];
		return r;

	}
	else
	{
		r1 = polynomial_mult(a,b,al,bl,n/2);
		r2 = polynomial_mult(a,b,al+n/2,bl+n/2,n/2);
		r3 = polynomial_mult(a,b,al,bl+n/2,n/2);
		r4 = polynomial_mult(a,b,al+n/2,bl,n/2);
		for(i=0;i<n-1;i++)
		{
			r[i] += r1[i];
			r[i+n/2] += r3[i] + r4[i];
			r[i+n] +=r2[i];
		}
	return r;
	}
}

void naive_polynomial_mult(int *a,int *b, int n,int *product)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			product[i+j] += a[i] * b[j];
}


int main()
{
	int n;int flag = 0;int pos =0;int diff;
	scanf("%d",&n);
	if(n%2 == 0)
	{
		if(n>2)
		{
			if(n%4 != 0)
			{
				n += 2;
				flag = 1;
			}
		}
	}
	else
	{
		diff = 4-n%4;
		n += diff;
		flag = 2;
	}
	int i,a[n],b[n];
	if(flag == 1)
	{
		a[0]=a[1]=b[0]=b[1]=0;
		pos = 2;
	}
	else if(flag == 2)
	{
		while(diff--)
		{
			a[pos]=b[pos]=0;
			pos++;
		}
	}

	for(i=pos;i<n;i++)
		scanf("%d",&a[i]);
	for(i=pos;i<n;i++)
		scanf("%d",&b[i]);

	int product[2*n-1]; 
	int *r = (int *) malloc(sizeof(int) * (2*n-1));
	for(i=0;i<(2*n-1);i++)
		r[i] = 0;
	for(i=0;i<(2*n-1);i++)
		product[i] = 0;

	r = polynomial_mult(a,b,0,0,n);
	naive_polynomial_mult(a,b,n,product);
	for(i=0;i<(2*n-1);i++)
	{
		if(product[i] != r[i])
		{
			printf("\nVerify fail\n");
			exit(-1);
		}
	}
	printf("\nSuccessful computation using divide & conquer\n");
	return 0;
}
	
