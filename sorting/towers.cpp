#include<bits/stdc++.h>
#include<math.h>
#include <set>


using namespace std;

int main(){
    multiset<int> towers;
    multiset<int>::iterator upper;
    int n;cin>>n;
    int curr;
    for(int i=0;i<n;i++){
        cin>>curr;
        upper = towers.upper_bound(curr);
        if(upper==towers.end()){
            towers.insert(curr);
        }else{
            towers.erase(upper);
            towers.insert(curr);
        }
    }

    cout<<towers.size();
}


