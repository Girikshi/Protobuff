#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> vect={1,2,3,4,5};
	int sum_of_elems=0;
	
	std::for_each(vect.begin(), vect.end(), [&] (int n) {
	//cout<<"\nelement is : "<<n;
    	sum_of_elems += n;
	});
	
	cout<<"\nSum of elements is : "<<sum_of_elems<<endl;
	
	return 0;
	
}

