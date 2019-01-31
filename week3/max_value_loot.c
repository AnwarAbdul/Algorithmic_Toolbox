#include<stdio.h>

void value_calculator(int *total_loot_weight,int weight_capacity,double unit_value,int weight,double *total_value)
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

void sort(double *unit_value,int *weight,int n)
{
	int i,j,largest;
	double temp;int temp1;
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
	double total_value;
	total_loot_weight = 0;
	total_value = 0;
	scanf("%d %d",&n,&weight_capacity);
	double unit_value[n];
	int weight[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&value,&weight[i]);
		unit_value[i] = (double)value/(double)(weight[i]);
	}
	sort(unit_value,weight,n);
	for(i=0;i<n;i++)
	{
		value_calculator(&total_loot_weight,weight_capacity,unit_value[i],weight[i],&total_value);
	}
//	for(i=0;i<n;i++)
//		printf("\n\n%lf %d\n",unit_value[i],weight[i]);
//	if(total_loot_weight > weight_capacity)
//		printf("0");
//	else
	printf("%0.4lf",total_value);
	return 0;
}



	




