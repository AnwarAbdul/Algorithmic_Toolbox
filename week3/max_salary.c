#include<stdio.h>
#include<math.h>

int digit_count(int num)
{
	int count = 1;
	while( num >= 10)
	{
		num = num /10;
		count ++;
	}
	return count;
}

int msd(int num,int shift)
{
	while(shift--)
	{
		num = num / 10;
	}
	return num % 10;
}

int compare(int a1,int a2)
{
	int i,j;

	int num1,num2;
	int swap = 0;
	
	num1 = digit_count(a1);
	num2 = digit_count(a2);

	if(num1 == num2)
	{
		if(a2 > a1)
			swap = 1;
	}
	else
	{
		if(msd(a2,num2-1) > msd(a1,num1-1))
			swap = 1;
		else if(msd(a2,num2-1) > msd(a1,num1-1))
			swap = 0;
		else
		{
			i = a1 * pow(10, num2);
			j = a2 * pow(10, num1);

			i = i + a2;
			j = j + a1;

			if(i>j)
				swap = 0;
			else if(j > i)
				swap = 1;
			else
				swap = 0;
		}
	}
	
	return swap;
}

void normal_sort(int *a,int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j] > a[i])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

void sort(int *a,int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(compare(a[i],a[j]))
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[100];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	normal_sort(a,n);
//	for(i=0;i<n;i++)
//		printf("\na[%d] = %d",i,a[i]);
	sort(a,n);
//	for(i=0;i<n;i++)
//		printf("\na[%d] = %d",i,a[i]);
//	printf("\n");
	for(i=0;i<n;i++)
		printf("%d",a[i]);
	return 0;
}
