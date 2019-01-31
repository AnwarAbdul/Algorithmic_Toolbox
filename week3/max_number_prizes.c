#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d",&n);
	int size = sqrt(2*n);
	int ar[size];
	int i,sum,pos;
	i=sum=1;
	pos=0;
	ar[pos++] = i;
	while(sum<n)
	{
		if(n==2)
		{
			ar[0] = 2;
			pos = 1;
			break;
		}
		i++;
		sum += i;
		if((n-sum) > (i))
			ar[pos++] = i;
		else
		{
			sum -= i;
			i = n-sum;
			ar[pos++] = i;
			sum += i;
		}
//		printf("sum = %d, i = %d\n",sum,i);
	}
	printf("%d\n",pos);
	for(i=0;i<pos;i++)
		printf("%d ",ar[i]);

	return 0;
}
