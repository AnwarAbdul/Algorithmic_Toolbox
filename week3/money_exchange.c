#include<stdio.h>


int coin_counter(int *total_value,int input,int denomination)
{
	int loop_count = 0;
	while(*total_value <= input)
	{
		loop_count++;
		*total_value += denomination;
	}
	*total_value -= denomination;
	if(loop_count > 1)
		return loop_count-1;
	else
		return 0;
}


int main()
{
	int input,*total_value,coin_count;
	int dummy = 0;
	total_value = &dummy;
	coin_count =0;
	scanf("%d",&input);
	coin_count += coin_counter(total_value,input,10);
	coin_count += coin_counter(total_value,input,5);
	coin_count += coin_counter(total_value,input,1);
	printf("%d",coin_count);
	return 0;
}

