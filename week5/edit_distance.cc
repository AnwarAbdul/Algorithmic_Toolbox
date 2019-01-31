#include<iostream>
#include<string>
#include<cstring>

using namespace std;


int sequence_alignment(char *s1,char *s2,int n1,int n2)
{
	int i,j;
	int insertions,deletions,mismatches,matches;
	int a[n1+1][n2+1];int min;
	/*
	cout<<"\nPrinting the strings using pointer reference\n";
	for(i=0;i<n1;i++)
		cout<<*(s1+i)<<" ";
	cout<<"\n";
	for(j=0;j<n2;j++)
		cout<<*(s2+j)<<" ";
	cout<<"\n";
	*/
	for(j=0;j<=n2;j++)
		a[0][j] = j;
	for(i=0;i<=n1;i++)
		a[i][0] =i;
	for(i=1;i<=n1;i++)
	{
		for(j=1;j<=n2;j++)
		{
			insertions = a[i-1][j] + 1;
			deletions = a[i][j-1] + 1;
			matches = a[i-1][j-1] ;
			mismatches = matches + 1;
			if(*(s1+i-1) == *(s2+j-1))
			{
				min = insertions;
				if(deletions < min)
					min = deletions;
				if(matches < min)
					min = matches;
				a[i][j] = min;
			}
			else
			{
				min = insertions;
				if(deletions < min)
					min = deletions;
				if(mismatches < min)
					min = mismatches;
				a[i][j] = min;
			}
		
		}
	}
	/*
	for(i=0;i<=n1;i++)
	{
		cout<<"\n";
		for(j=0;j<=n2;j++)
		{
			cout<<a[i][j]<<" ";
		}
	}
	cout<<"\n";
	*/

	return a[n1][n2];
}
	
int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	int edit_distance;
//	cout<<s1<<" "<<s2<<"\n";
	int n1= s1.length();
	int n2= s2.length();
	char s1_arr[n1+1];char s2_arr[n2+1];
	strcpy(s1_arr,s1.c_str());
	strcpy(s2_arr,s2.c_str());
	edit_distance = sequence_alignment(s1_arr,s2_arr,n1,n2);
	cout<<edit_distance;
	return 0;
}

