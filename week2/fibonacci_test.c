/*Prints out fn mod m. Not good for large n. For large n, refer other file but there will be no printing for it
 */

 
#include<stdio.h>
#include<inttypes.h>

uint64_t fibonacci(uint64_t n,uint64_t mod)
{
	uint64_t fib[n+1];
	fib[0]=0;fib[1]=1;
	printf("%" PRIu64 " ",fib[0]%mod);
	printf("%" PRIu64 " ",fib[1]%mod);
	for(uint64_t i=2;i<=n;i++)
	{
		fib[i]=fib[i-1] + fib[i-2];
		printf("%" PRIu64 " ",fib[i]%mod);
	}
	return fib[n];
}


int main()
{
	uint64_t n,fib,mod;
	scanf("%" PRIu64 "%" PRIu64,&n,&mod);
	fib=fibonacci(n,mod);
//	printf("\n%"PRIu64, fib);
	return 0;
}
