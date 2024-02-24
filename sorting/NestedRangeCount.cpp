#include<bits/stdc++.h>
#include<math.h>
#include <set>
#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;

struct range{
    int a;
    int b;
    int i;
};
bool compareByLengthLess(const range &f, const range &s)
{
    if(f.a == s.a) return f.b < s.b;
    return f.a < s.a;
}
bool compareByLengthLessPair(const pair<int,int> &f, const pair<int,int> &s)
{
    return f.first < s.first;
}
bool compareByLengthBigger(const range &f, const range &s)
{
    return f.a > s.a;
}
int main(){
    int n;
    cin>>n;
    multiset<int> bounders;
    vector<range> ranges;
    vector<int> contains;
    vector<int> contained;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        ranges.push_back(range {a,b,i});
        contains.push_back(0);
        contained.push_back(0);
    }
    std::sort(ranges.begin(), ranges.end(),compareByLengthLess);
    for(int i=0;i<n;i++){
        auto it= bounders.lower_bound(ranges[i].b);
        contained[ranges[i].i]=i-distance(bounders.begin(), it);
        bounders.insert(ranges[i].b);
    }
    bounders.clear();
    for(int i=n-1;i>=0;i--){
        auto it=bounders.upper_bound(ranges[i].b);
        contains[ranges[i].i]=distance(bounders.begin(), it);
        bounders.insert(ranges[i].b);
    }

    for(int i=0;i<n;i++){
        cout<<contains[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<contained[i]<<" ";
    }

}
