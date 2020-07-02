#include<bits/stdc++.h>
using namespace std;

int main()
{
        //unordered_set declaration
        unordered_set<int> s={11,12,13,11,15,13,16};

        //insertion of elements in unordered_set
        s.insert(14);
        s.emplace(17);

        //print the elements in unordered_set
        cout<<"\nElements in the unordered_set are : ";
        for(auto i : s)
         cout<<i<<" ";

        //delete elements in unordered_set
        s.erase(s.begin());
        s.erase(17);

        //print elements in the unordered_set after deletion
        cout<<"\nElements in the unordered_set after deletion are : ";
        for(auto i :s)
        cout<<i<<" ";
        cout<<"\n";
        return 0;
}

