#include<bits/stdc++.h>
using namespace std;

int main()
{
        //unordered_multiset declaration
        unordered_multiset<int> s={11,12,13,11,15,13,16};

        //insertion of elements in unordered_multiset
        s.insert(14);
        s.emplace(17);

        //print the elements in unordered_multiset
        cout<<"\nElements in the unordered_multiset are : ";
        for(auto i : s)
         cout<<i<<" ";

        //delete elements in unordered_multiset
        s.erase(s.begin());
        s.erase(11);

        //print elements in the unordered_multiset after deletion
        cout<<"\nElements in the unordered_multiset after deletion are : ";
        for(auto i :s)
        cout<<i<<" ";
        cout<<"\n";
        return 0;
}

