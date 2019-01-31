#include<stdio.h>
#include<inttypes.h>

uint64_t fibonacci(uint64_t n)
{
	uint64_t fib[n+1];
	fib[0]=0;fib[1]=1;
	printf("%" PRIu64 " ",fib[0]);
	printf("%" PRIu64 " ",fib[1]);
	for(uint64_t i=2;i<=n;i++)
	{
		fib[i]=fib[i-1] + fib[i-2];
		printf("%" PRIu64 " ",fib[i]);
	}
	return fib[n];
}


int main()
{
	uint64_t n,fib;
	scanf("%" PRIu64,&n);
	fib=fibonacci(n);
	printf("\n%"PRIu64, fib);
	return 0;
}
