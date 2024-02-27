#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

bool sortByLess(pair<ll,ll> a,pair<ll,ll> b){
    return a.first>b.first;
}
bool findTarget(vector<pair<ll,ll>> numbers, ll indexToIgnore, ll target){
    ll l,r,currSum;
    if(indexToIgnore==0){
        l=2;
        r=numbers.size()-2;
        currSum=numbers[l-1].first+numbers[r+1].first;
    }else if(indexToIgnore==numbers.size()-1){
        l=1;
        r=numbers.size()-3;
        currSum=numbers[l-1].first+numbers[r+1].first;
    }else{
        l=1;
        r=numbers.size()-2;
        currSum=numbers[l-1].first+numbers[r+1].first;
    }
    while(l<=r){
        if(currSum>target){
            currSum-=numbers[r+1].first;
            r-=1;
            if(indexToIgnore==r+1){
                r--;
            }
            currSum+=numbers[r+1].first;
        }else if(currSum<target){
            currSum-=numbers[l-1].first;
            l+=1;
            if(indexToIgnore==l-1){
                l+=1;
            }
            currSum+=numbers[l-1].first;
        }else{
            cout<<numbers[l-1].second<<" "<<numbers[r+1].second<<" "<<numbers[indexToIgnore].second;
            return true;
        }
    }
    if(currSum==target){
        cout<<numbers[l-1].second<<" "<<numbers[r+1].second<<" "<<numbers[indexToIgnore].second;
        return true;
    }
    return false;

}
int main(){
    ll n,target;
    cin>>n>>target;
    vector<pair<ll,ll>> numbers;
    if(n<=2){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(ll i=0;i<n;i++){
        ll a; cin>>a;
        numbers.push_back(make_pair(a,i+1));
    }
    sort(numbers.rbegin(),numbers.rend(),sortByLess);

    for(ll i=0;i<n;i++){
        bool curr=findTarget(numbers,i,target-numbers[i].first);
        if(curr){
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
}
