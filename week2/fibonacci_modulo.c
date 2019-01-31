#include<stdio.h>
#include<inttypes.h>

uint64_t fibonacci_modulo_period(uint64_t mod)
{
	uint64_t fib,period,fib_next;
	uint64_t a,b,count;
	a=0;b=1,count=2;
	uint64_t i=2;
	while(1)
	{
		fib=(a%mod + b%mod)%mod;
		if(fib%mod == 0)
		{
			fib_next=(fib+b%mod)%mod;
			if(fib_next == 1)
			{
				period = i;
				break;
			}
		}
	a=b%mod;
	b=fib%mod;
	i=i+1;
	count = count +1;	
	}
	return period;
}

uint64_t fibonacci_modulo(uint64_t n,uint64_t mod)
{
	uint64_t fib[n+1],period;
	fib[0]=0;fib[1]=1;
	for(uint64_t i=2;i<=n;i++)
	{
		fib[i]=(fib[i-1]%mod + fib[i-2]%mod)%mod;
	}
	return fib[n];
}

int main()
{
	uint64_t n,fib_modulo,mod,period;
	scanf("%" PRIu64 "%" PRIu64,&n,&mod);
	period=fibonacci_modulo_period(mod);
	fib_modulo=fibonacci_modulo(n%period,mod);
	printf("%"PRIu64, fib_modulo);
	return 0;
}
