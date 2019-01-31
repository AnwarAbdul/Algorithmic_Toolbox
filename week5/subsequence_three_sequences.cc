#include<iostream>
#include<iomanip>
#include<stdlib.h>


using namespace std;

int minimum(int insertions,int deletions,int matches_mismatches)
{
	int lowest = insertions;
	if(deletions < lowest)
		lowest = deletions;
	if(matches_mismatches < lowest)
		lowest = matches_mismatches;
	return lowest;
}

int maximum(int insertions,int deletions,int matches_mismatches)
{
	int highest = insertions;
	if(deletions > highest)
		highest = deletions;
	if(matches_mismatches > highest)
		highest = matches_mismatches;
	return highest;
}



int backtrack_edit_distance_matrix(int **a,int n1,int n2,int *s1,int *s2,int *temp,int option)
{
	int subsequence_length = 0;
	int i,j;
	i = n1;
	j = n2;
	while(i >= 1 && j >= 1)
	{
		if((a[i-1][j] == a[i][j-1]) && (a[i-1][j] == a[i-1][j-1]) && ((a[i][j] -1) == a[i-1][j-1]))
		{
			//cout<<"\nSubsequence print from both strings as :" <<s1[i-1]<<" "<<s2[j-1]<<" i = "<<i<<" j = "<<j<<"\n";
			if(temp != NULL)
				temp[subsequence_length] = s1[i-1];
			subsequence_length++;
			i--;
			j--;
		}
		else 
		{
			if(option == 0)
			{
				if((a[i][j]) == a[i-1][j])
					i--;
				else
					j--;
			}
			else 
			{
				if((a[i][j]) == a[i][j-1])
					j--;
				else
					i--;
			}
		}

	}
	return subsequence_length;
}

int sequence_alignment(int *a,int *b,int *temp,int n1,int n2,int option)
{
	int **edit_distance_matrix = (int **)malloc(sizeof(int *) * (n1+1));
	int i,j;
	for(i=0;i<=n1;i++)
		edit_distance_matrix[i] = (int *)malloc(sizeof(int) * (n2+1));
	for(i=0;i<=n1;i++)
		edit_distance_matrix[i][0] = 0;
	for(j=0;j<=n2;j++)
		edit_distance_matrix[0][j] = 0;
	int insertions,deletions,matches,mismatches;
	for(i=1;i<=n1;i++)
	{
		for(j=1;j<=n2;j++)
		{
			insertions = edit_distance_matrix[i-1][j] - 0;
			deletions = edit_distance_matrix[i][j-1] - 0;
			matches = edit_distance_matrix[i-1][j-1] + 1;
			mismatches = matches - 1;
			if(a[i-1] == b[j-1])
				edit_distance_matrix[i][j] = maximum(insertions,deletions,matches);
			else
				edit_distance_matrix[i][j] = maximum(insertions,deletions,mismatches);
		}

	}
	/*	
	cout<<"\nTo display edit distance matrix\n";
	for(i=0;i<=n1;i++)
	{
		cout<<"\n";
		for(j=0;j<=n2;j++)
			cout<<edit_distance_matrix[i][j]<<setw(5);
	}
	cout<<"\n";
	*/
	int subsequence_length = backtrack_edit_distance_matrix(edit_distance_matrix,n1,n2,a,b,temp,option);
	return subsequence_length;
}

int main()
{
	int n1,n2,n3,i;
	cin>>n1;
	int a[n1];
	for(i=0;i<n1;i++)
		cin>>a[i];
	
	cin>>n2;
	int b[n2];
	for(i=0;i<n2;i++)
		cin>>b[i];
	
	cin>>n3;
	int c[n3];
	for(i=0;i<n3;i++)
		cin>>c[i];
	
	int *temp1,*temp2;
	if(n1 > n2)
	{
		if(n3 > n1)
			{
				temp1 = (int *)malloc(sizeof(int) * n3);
				temp2 = (int *)malloc(sizeof(int) * n3);
			}
		else
			{
				temp1 = (int *)malloc(sizeof(int) * n1);
				temp2 = (int *)malloc(sizeof(int) * n1);
			}
	}
	else
	{
		if(n3 > n2)
			{
				temp1 = (int *)malloc(sizeof(int) * n3);
				temp2 = (int *)malloc(sizeof(int) * n3);
			}
		else
			{
				temp1 = (int *)malloc(sizeof(int) * n2);
				temp2 = (int *)malloc(sizeof(int) * n2);
			}
	}
	
	int subsequence_length1,subsequence_length2,subsequence_length3,subsequence_length4;
	
	subsequence_length1 = sequence_alignment(a,b,temp1,n1,n2,0);
	subsequence_length2 = sequence_alignment(a,b,temp2,n1,n2,1);
	
	/*
	cout<<"\nTo display temp1 before reversal\n";
	for(i=0;i<subsequence_length1;i++)
		cout<<temp1[i]<<setw(5);
	cout<<"\nTo display temp2 before reversal\n";
	for(i=0;i<subsequence_length2;i++)
		cout<<temp2[i]<<setw(5);
	*/
	
	int temp;
	for(i=0;i<subsequence_length1/2;i++)
	{
		temp = temp1[i];
		temp1[i] = temp1[subsequence_length1 - 1 - i];
		temp1[subsequence_length1 -1 - i] = temp;
	}
	for(i=0;i<subsequence_length2/2;i++)
	{
		temp = temp2[i];
		temp2[i] = temp2[subsequence_length2 - 1 - i];
		temp2[subsequence_length2 - 1 -  i] = temp;
	}
	
	/*
	cout<<"\nTo display temp1\n";
	for(i=0;i<subsequence_length1;i++)
		cout<<temp1[i]<<setw(5);
	cout<<"\nTo display temp2\n";
	for(i=0;i<subsequence_length2;i++)
		cout<<temp2[i]<<setw(5);
	*/
	subsequence_length3 = sequence_alignment(temp1,c,NULL,subsequence_length1,n3,0);
	subsequence_length4 = sequence_alignment(temp2,c,NULL,subsequence_length2,n3,1);
	
	if(subsequence_length3 > subsequence_length4)
		cout<<subsequence_length3;
	else
		cout<<subsequence_length4;
	return 0;
}
