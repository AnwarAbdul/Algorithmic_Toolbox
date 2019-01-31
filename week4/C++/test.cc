#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;


int display(int n)
{
	return n;
}

int main()
{
	long int a = pow(-10,9);
	cout<<"Hello There...\n";
	cout<<display(4);
	float f = 4.883999;
	cout<<setprecision(3)<<fixed;
	cout<<"\n"<<f<<"\n";
	cout<<"a = "<<setprecision(15)<<fixed<<a<<"\n";
	double d = sqrt(pow(a-1,2) + pow(a-2,2));
	cout<<"\nd = "<<fixed<<setprecision(2)<<d<<"\n";
	return 0;
}
