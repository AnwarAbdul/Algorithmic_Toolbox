#include<stdio.h>
#include<inttypes.h>

int64_t fibonacci_modulo_period(uint64_t mod)
{
	int64_t fib,period,fib_next;
	int64_t a,b,count;
	a=0;b=1,count=2;
	int64_t i=2;
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

int64_t sum_fibonacci_modulo(uint64_t n,uint64_t period,uint64_t mod)
{
	int64_t a,b,fib,sum,period_temp,i;
	a=0;b=1;
	period_temp=period;
	if(n==0)
		sum = 0;
	else 
		sum = 1;
	if(n<period)
		period_temp = n+1;
//	printf("\nperiod_temp = %"PRId64,period_temp);
	for(i=2;i<period_temp;i++)
	{
		fib=(a%mod + b%mod)%mod;
		sum = (sum + fib)%mod;
		a=b;
		b=fib;
	}
//	printf("\nsum till period_temp = %"PRId64"\n",sum);
	if(n/period ==0)
		return sum;
	else 
	{
		sum = sum + sum*(n/period);
//		printf("\nsum n/period times = %"PRId64"\n",sum);
		a=0;b=1;
		if(n%period!=0)
			sum = sum + a + b;
		for(i=2;i<=(n%period);i++)
		{
			fib = (a%mod + b%mod)%mod;
			sum = (sum + fib)%mod;
			a=b;
			b=fib;
//			printf("%"PRId64".\n",i); 
		}
	}	
	return sum;
}

int main()
{
	int64_t n1,n2,fib_modulo_sum_1,fib_modulo_sum_2,mod,period;
	int diff;
	mod = 10;
	scanf("%" PRId64"%"PRIu64,&n1,&n2);
	period=fibonacci_modulo_period(mod);
	if(n1==0)
		fib_modulo_sum_1=sum_fibonacci_modulo(n1,period,mod);
	else
		fib_modulo_sum_1=sum_fibonacci_modulo(n1-1,period,mod);
//	printf("\nfib_modulo_sum_1 = %"PRId64,fib_modulo_sum_1);
	fib_modulo_sum_2=sum_fibonacci_modulo(n2,period,mod);
//	printf("\nfib_modulo_sum_2 = %"PRId64"\n",fib_modulo_sum_2);
	if(fib_modulo_sum_1>fib_modulo_sum_2)
		fib_modulo_sum_2 += 10;
	diff = fib_modulo_sum_2 - fib_modulo_sum_1;
	diff = diff%mod;
	printf("%d",diff);
	return 0;
}
