#include<stdio.h>

int main()
{
	printf("0\n");
	int i,j;
	int *p;
	int b=3;
	p = &b;
	int c = *p + b;
	printf("c=%d\n",c);
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(i==4)
			{
				printf("i=%d,j=%d\n",i,j);
			}
		}
	}
	return 0;
}

