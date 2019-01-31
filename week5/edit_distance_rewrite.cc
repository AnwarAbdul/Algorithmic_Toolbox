#include<iostream>
#include<string>
#include<cstring>


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

int sequence_alignment_check(char *s1,char *s2,int n1,int n2)
{
	int edit_distance_matrix[n1+1][n2+1];
	int i,j;
	int insertions,deletions,matches,mismatches;
	for(i=0;i<=n1;i++)
		edit_distance_matrix[i][0] = i;
	for(j=0;j<=n2;j++)
		edit_distance_matrix[0][j] = j;
	for(i=1;i<=n1;i++)
	{
		for(j=1;j<=n2;j++)
		{
			insertions = edit_distance_matrix[i-1][j] + 1;
			deletions = edit_distance_matrix[i][j-1] + 1;
			matches = edit_distance_matrix[i-1][j-1];
			mismatches = matches + 1;
			if(s1[i-1] == s2[j-1])
				edit_distance_matrix[i][j] = minimum(insertions,deletions,matches);
			else
				edit_distance_matrix[i][j] = minimum(insertions,deletions,mismatches);
		}
	}
	cout<<"\nTo display edit distance matrix\n";
	for(i=0;i<=n1;i++)
	{
		cout<<"\n";
		for(j=0;j<=n2;j++)
			cout<<edit_distance_matrix[i][j]<<" ";
	}
	cout<<"\n";
	return edit_distance_matrix[n1][n2];
}

int main()
{
	string str1,str2;
	cin>>str1;
	cin>>str2;
	int n1 = str1.length();
	int n2 = str2.length();
	char s1[n1+1],s2[n2+1];
	strcpy(s1,str1.c_str());
	strcpy(s2,str2.c_str());
	int edit_distance = sequence_alignment_check(s1,s2,n1,n2);
	cout<<edit_distance;
	return 0;
}

