#include<stdio.h>
#include<inttypes.h>

int64_t search(int n,int64_t *array)
{	int index_largest=0;
	for(int i=1;i<n;i++)
	{
		if(array[i] > array[index_largest])
			index_largest = i;
	}
	int64_t temp;
	if(index_largest != n-1)
	{
		temp = array[n-1];
		array[n-1] = array[index_largest];
		array[index_largest] = temp;
	}
	return array[n-1];
}

int main()
{
	int n;;
	scanf("%d",&n);
	int64_t array[n];
	for (int i=0;i<n;i++)
	{
		scanf("%" PRId64,&array[i]);
	}
	int64_t largest = search(n,array);
	int64_t second_largest = search(n-1,array);
	printf("%" PRId64,largest * second_largest);
	return 0;
}
