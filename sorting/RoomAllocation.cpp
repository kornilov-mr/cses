#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
struct range{
    int first;
    int second;
    int i;
};
bool compareByLengthLess(const range &f, const range &s)
{
    return f.first > s.first;
}
int main(){
    int n;
    cin>>n;
    int answers[n];
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> rooms;
    vector<range> customers;

    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        customers.push_back({a,b,i});
    }
    sort(customers.rbegin(),customers.rend(),compareByLengthLess);
    rooms.push(make_pair(customers[0].second,1));
    int max=1;
    answers[customers[0].i]=1;
    for(int i=1;i<n;i++){
//        cout<<rooms.top().first<<endl;
        if(customers[i].first<=rooms.top().first){
            max+=1;
            rooms.push(make_pair(customers[i].second,max));
            answers[customers[i].i]=max;
        }else{
            pair<int,int> data= rooms.top();
            answers[customers[i].i]=data.second;
            rooms.pop();
            rooms.push(make_pair(customers[i].second,data.second));
        }
    }
    cout<<max<<endl;
    for(int i=0;i<n;i++){
        cout<<answers[i]<<" ";
    }
}