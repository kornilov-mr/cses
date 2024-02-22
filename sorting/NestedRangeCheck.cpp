#include<bits/stdc++.h>
#include<math.h>
#include <set>
#include<iostream>
using namespace std;

struct range{
    int a;
    int b;
    int i;
};
bool compareByLengthLess(const range &f, const range &s)
{
    return f.a < s.a;
}
bool compareByLengthBigger(const range &f, const range &s)
{
    return f.a > s.a;
}
int main(){
    int n;
    cin>>n;
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
    int max=ranges[0].b;

    for(int i=1;i<n;i++){
        if(max>=ranges[i].b){
                contains[ranges[i].i]=1;
        }else{
            max=ranges[i].b;
        }
    }
    std::sort(ranges.begin(), ranges.end(),compareByLengthBigger);
    int min=ranges[0].b;

    for(int i=1;i<n;i++){
        if(min<=ranges[i].b){
            contained[ranges[i].i]=1;
        }else{
            min=ranges[i].b;
        }
    }
    for(int i=0;i<n;i++){
        cout<<contained[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<contains[i]<<" ";
    }

}
