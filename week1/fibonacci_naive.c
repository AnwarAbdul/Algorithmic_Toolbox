#include<stdio.h>
#include<inttypes.h>

uint64_t fibonacci(uint64_t n)
{
	uint64_t fib;
	if(n<=1)
	{
		fib = n;
	}
	else
	{
		fib = fibonacci(n-1) + fibonacci(n-2);
	}
	return fib;
}


int main()
{
	uint64_t n,fib;
	scanf("%" PRIu64,&n);
	fib=fibonacci(n);
	printf("%"PRIu64, fib);
	return 0;
}
