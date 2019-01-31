#include<stdio.h>

void sort(int *a,int *b,int n)
{
	int i,j;
	int temp,temp1;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(b[j] < b[i])
			{
				temp = b[j];temp1 = a[j];
				b[j] = b[i];a[j] = a[i];
				b[i] = temp; a[i] = temp1;
			}
		}

	}
}



int main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
		scanf("%d %d",&a[i],&b[i]);
	sort(a,b,n);
//	for(i=0;i<n;i++)
//		printf("%lu,%lu\n",a[i],b[i]);
	int pos =0;
	int temp;
	int final[n];
	int overlap=0;
	i=0;
	while((i != n) && (n!=1))
	{
		overlap = 0;
		temp = b[i];
		for(j=i+1;j<n;j++)
		{
			if(temp >= a[j] && temp <= b[j])
			{
//				printf("\nInside overlap loop, i=%d j=%d , temp = %lu\n",i,j,temp);
				if(pos == 0)
				{
					final[pos] = temp;
//					printf("\nInside pos = 0 inside overlap, loop, final[%lu] = %lu count = %lu\n",pos,final[pos],count);
					pos++;
				}
				else if( a[i] <=  final[pos-1]  )
				{
					overlap = 1;
//					printf("\nInside duplication check inside overlap, loop, final[%lu] = %lu count = %lu\n",pos-1,final[pos-1],count);
					continue;
				}
				else
				{
					final[pos] = temp;
//					printf("\nInside else loop inside overlap, loop, final[%lu] = %lu count = %lu\n",pos,final[pos],count);
					pos++;
				}
				overlap = 1;
			}
		}
		if(!overlap)
		{
//			printf("\nInside non-overlap loop,i=%d j=%d, temp = %lu\n",i,j,temp);
			if(pos == 0)
			{
				final[pos] = temp;
				pos++;
			}
			else if( a[i] <= final[pos-1] )
			{
				i=i+1;
				continue;
			}
			else
			{
				final[pos] = temp; 
				pos++;
			}
			if(i==(n-2))
			{
				final[pos] = b[n-1];
				pos++;
				break;
			}
				
		}
		i=i+1;
	}
	if(n==1)
	{
		final[pos] = b[0];
		pos++;
	}
	printf("%d\n",pos);
	for(i=0;i<pos;i++)
		printf("%d ",final[i]);
	return 0;
}


