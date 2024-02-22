#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> traffic;
    multiset<int> distances;
    multiset<int>::iterator lower;
    traffic.insert(0);
    int s;cin>>s;
    traffic.insert(s);
    distances.insert(s);
    int n;cin>>n;
    int curr;
    int max=0;
    for(int i=0;i<n;i++){
        cin>>curr;
        traffic.insert(curr);
        auto it = traffic.find(curr);

        int prevInt=*prev(it);
        int nextInt=*next(it);

        distances.erase(distances.find(nextInt-prevInt));
        distances.insert(curr-prevInt);
        distances.insert(nextInt-curr);

        cout<<*distances.rbegin()<<" ";
    }
}