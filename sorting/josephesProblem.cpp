#include<iostream>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
struct less {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};
template <typename T>
using ordered_set= tree<T,null_type,less<T>,rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;

int main() {
    int n,k;
    cin >> n; cin>>k;
    ordered_set<int> numbers;
    for (int i = 1; i < n + 1; i++) {
        numbers.insert(i);
    }
    k+=1;
    int realI = k-1;
    realI %= numbers.size();
    for (int i = 0; i < n; i++) {
        int itemToErase=*numbers.find_by_order(realI);
        cout<<itemToErase<<" ";
        numbers.erase(itemToErase);
        realI += k-1;
        if(numbers.size()==0){
            break;
        }
        realI %= numbers.size();
    }
}