#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void value_calculator(int *total_loot_weight,int weight_capacity,float unit_value,int weight,float *total_value)
{	
	if((*total_loot_weight + weight) <=  weight_capacity)
	{
		*total_loot_weight += weight;
		*total_value += unit_value * weight;
	}
	else
	{
		if(*total_loot_weight  < weight_capacity)
		{
			*total_value += unit_value * (weight_capacity - *total_loot_weight);
			*total_loot_weight = weight_capacity;

		}
	}

}

void sort(float *unit_value,int *weight,int n)
{
	int i,j,largest;
	float temp;int temp1;
	for(i=0;i<n;i++)
	{
		largest = i;
		for(j=i+1;j<n;j++)
		{
			if((unit_value[j] > unit_value[largest]) || ((unit_value[j] == unit_value[largest]) && (weight[j] > weight[largest])))
			{
				temp = unit_value[largest];temp1 = weight[largest];
				unit_value[largest] = unit_value[j];
				weight[largest] = weight[j];
				unit_value[j] = temp;
				weight[j]= temp1;
			}
		}
	}
}


int main()
{
	int n,weight_capacity,i,value,total_loot_weight;
	float total_value;
	float unit_value[1000];
	int weight[1000];
	total_loot_weight = 0;
	total_value = 0;
	int upper = 2*10^6 + 1;
	int lower = 1;
	srand(time(NULL));
	int test_loops;
	scanf("%d",&test_loops);
for(int j=0;j<test_loops;j++)
{	
	total_value = 0;
	total_loot_weight = 0;	
	n = rand() % (1000) + 1;
	weight_capacity = (rand() % (upper-lower)) + lower;
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		value = ( rand() % (upper - lower)) + lower;
	        weight[i] = ( rand() % (upper - lower)) + lower;	
		unit_value[i] = (float)value/(float)(weight[i]);
	}
	sort(unit_value,weight,n);
	for(i=0;i<n;i++)
	{
		value_calculator(&total_loot_weight,weight_capacity,unit_value[i],weight[i],&total_value);
	}
	if(total_loot_weight > weight_capacity)
	{
		printf("%0.4f\n",total_value);
		for(i=0;i<n;i++)
			printf("\n%f %d\n",unit_value[i],weight[i]);
		printf("\n****Algorithm Failed n=%d weight_capacity=%d total_loot_weight=%d\n",n,weight_capacity,total_loot_weight);
		exit(1);
	}
}
	printf("\nAlgotithm is working\n");
	return 0;
}



	




