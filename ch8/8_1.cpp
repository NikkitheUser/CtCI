#include <vector>
#include <iostream>
// triple step
using namespace std;

int countWays(int n , vector<int> v){

	if (n==0){
		return 1;
	}

	int sum = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		if(n>=v[i]){
			sum = sum + countWays((n-v[i]),v);
		}	
	}
	return sum;
}

int main(int argc, char const *argv[])
{			

	vector<int> v;	// vector to store possible step sizes
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
cout<<"a kid can hop on either 2, 2 or 3 steps at a time. we are gonna assume that there are 6 total steps."<<endl;
	int noOfWays = countWays(6,v);
	cout<<noOfWays<<endl;	// Total number of stairs = 6

	return 0;
}
