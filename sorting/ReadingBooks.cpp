using namespace std;
#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
int main(){
    ll n; cin>>n;
    vector<ll> books;
    for(ll i=0;i<n;i++){
        ll a; cin>>a;
        books.push_back(a);
    }
    sort(books.rbegin(),books.rend());
    if(n==1){
        cout<<books[0]*2;
        return 0;
    }
    if(n==2){
        cout<<max(books[1],books[0])*2;
        return 0;
    }
    ll l=1; ll r=n-2;
    ll countl=books[0]; ll countr=books[n-1];
    while(l<=r){
        if(countl<countr){
            countl+=books[l];
            l+=1;
        }else{
            countr+=books[r];
            r-=1;
        }
    }
    if(countl>countr){
        if(countl-books[l-1]>=countl-countr){
               cout<<countl+countr;
        }else{
            cout<< countl+countr-((countl-books[l-1])-(countl-countr));
        }
    }else if(countl<countr){
        if(r!=n-2){
            cout<< countl+countr;
        }else{
            cout<< max(countl,countr)*2;
        }
    }else{
        cout<< max(countl,countr)*2;
    }
}