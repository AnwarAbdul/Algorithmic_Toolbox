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

uint64_t sum_fibonacci_modulo(uint64_t n,uint64_t period,uint64_t mod)
{
	uint64_t a,b,fib,sum,period_temp,i;
	a=0;b=1;
	period_temp=period;
	if(n==0)
		sum = 0;
	else 
		sum = 1;
	if(n<period)
		period_temp = n+1;
//	printf("\nperiod_temp = %"PRIu64,period_temp);
	for(i=2;i<period_temp;i++)
	{
		fib=(a%mod + b%mod)%mod;
		sum = (sum + (fib*fib)%mod)%mod;
		a=b;
		b=fib;
	}
//	printf("\nsum till period_temp = %"PRIu64"\n",sum);
	if(n/period ==0)
		return sum;
	else 
	{
		sum = sum + sum*(n/period);
//		printf("\nsum n/period times = %"PRIu64"\n",sum);
		a=0;b=1;
		if(n%period!=0)
			sum = sum + a + b;
		for(i=2;i<=(n%period);i++)
		{
			fib = (a%mod + b%mod)%mod;
			sum = (sum + (fib*fib)%mod)%mod;
			a=b;
			b=fib;
//			printf("%"PRIu64".\n",i); 
		}
	}	
	return sum;
}

int main()
{
	uint64_t n,fib_modulo_sum,mod,period;
	mod = 10;
	scanf("%" PRIu64,&n);
	period=fibonacci_modulo_period(mod);
	fib_modulo_sum=sum_fibonacci_modulo(n,period,mod);
	printf("%"PRIu64, fib_modulo_sum);
	return 0;
}
