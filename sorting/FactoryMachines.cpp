#include<iostream>
#include<bits/stdc++.h>
#include <math.h>
using namespace std;
vector<long long> machines;

long long getProducts(long long n){
    long long ans=0;
    for(long long i=0;i<machines.size();i++){
        ans+=n/machines[i];
        if(ans>=1e18){
            return ans;
        }
    }
    return ans;
}
long long binarySearch(long long min,long long max,long long target){
    long long mid=(min+max)/2;
    long long currProducts = getProducts(mid);
    if(currProducts>=target){
        if(getProducts(mid-1)<target){
            return mid;
        }
        return binarySearch(min,mid,target);
    }else if (currProducts<target){
        return binarySearch(mid,max,target);
    }
}
int main(){
    long long n,t;
    cin>>n>>t;
    for(long long i=0;i<n;i++){
        long long a; cin>>a;
        machines.push_back(a);
    }
    long long ans = binarySearch(0,1000000000000000002,t);
    cout<<ans;
}