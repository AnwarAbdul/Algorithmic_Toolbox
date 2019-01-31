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



int backtrack_edit_distance_matrix(int **a,int n1,int n2)
{
	int subsequence_length = 0;
	int i,j;
	i = n1;
	j = n2;
	while(i >= 1 && j >= 1)
	{
		if((a[i-1][j-1] == (a[i-1][j]) && (a[i-1][j] == a[i][j-1])) && ((a[i][j]-1) == a[i-1][j-1]) )
		{
			subsequence_length++;
			i--;
			j--;
		}

		else if((a[i-1][j]) == a[i][j] ) 
			i--;
		else
			j--;
	}
	return subsequence_length;
}

int sequence_alignment(int *a,int *b,int n1,int n2)
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
	int subsequence_length = backtrack_edit_distance_matrix(edit_distance_matrix,n1,n2);
	return subsequence_length;
}

int main()
{
	int n1,n2;
	cin>>n1;
	int a[n1];
	int i;
	for(i=0;i<n1;i++)
		cin>>a[i];
	cin>>n2;
	int b[n2];
	for(i=0;i<n2;i++)
		cin>>b[i];
	int subsequence_length = sequence_alignment(a,b,n1,n2);
	cout<<subsequence_length;
	return 0;
}
