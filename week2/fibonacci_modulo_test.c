/* Prints the period for fn mod m along with the value mapped withindex n
 */
#include<stdio.h>
#include<inttypes.h>

uint64_t fibonacci_modulo_period(uint64_t mod)
{
	uint64_t fib,period,fib_next;
	uint64_t a,b,count;
	a=0;b=1,count=2;
	printf("\n""%d. ""%" PRIu64 " ",0,a%mod);
	printf("\n""%d. ""%" PRIu64 " ",1,b%mod);
	uint64_t i=2;
	while(1)
	{
		fib=(a%mod + b%mod)%mod;
		printf("\n""%"PRIu64". ""%" PRIu64 " ",count,fib%mod);
		if(fib%mod == 0)
		{
			fib_next=(fib+b%mod)%mod;
			if(fib_next == 1)
			{
				period = i;
				printf("\nPeriod is %"PRIu64"\n",period);
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


int main()
{
	uint64_t n,fib_modulo,mod,period;
	scanf("%" PRIu64,&mod);
	period=fibonacci_modulo_period(mod);
//	fib_modulo=fibonacci_modulo(n%period,mod);
//	printf("%"PRIu64, fib_modulo);
	return 0;
}
