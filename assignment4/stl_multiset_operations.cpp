#include<bits/stdc++.h>
using namespace std;

int main()
{
        //multiset declaration
        multiset<int> s={11,12,13,11,15,13,16};

        //insertion of elements in multiset
        s.insert(14);
        s.emplace(17);

        //print the elements in multiset
        cout<<"\nElements in the multiset are : ";
        for(auto i : s)
         cout<<i<<" ";

        //delete elements in multiset
        s.erase(s.begin());
        s.erase(11);

        //print elements in the multiset after deletion
        cout<<"\nElements in the multiset after deletion are : ";
        for(auto i :s)
        cout<<i<<" ";
        cout<<"\n";
        return 0;
}

