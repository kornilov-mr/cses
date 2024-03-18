#include <bits/stdc++.h>
#include <math.h>
#include <queue>
using namespace std;


/* Data Type  */
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* Functions */
/* Loop */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)

#define pb push_back
#define eb emplace_back

/* Printing vector */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* Utility */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
const ll mod = 1e9 + 7;

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;


int main() {
    vector<vector<int>> edges;
    vector<int> seen;
    vector<vector<int>> paths;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    edges.resize(n);
    seen.resize(n);
    map<int,int> edgesCount;
    set<pii> nodes;
    ll dp[n];
    f(i,0,n){
        dp[i]=0;

        seen.push_back(0);
    }
    dp[0]=1;

    f(i,0,m){
        int a,b; cin>>a>>b;
        edges[a-1].push_back(b-1);
        edgesCount[b-1]+=1;
    }

    f(i,0,n){
        nodes.insert({edgesCount[i],i});
    }
    while(!nodes.empty()){
        pii data = *nodes.begin();
        nodes.erase(data);
        for(int edge: edges[data.second]){
            dp[edge]=(dp[edge]+dp[data.second])%mod;
            nodes.erase({edgesCount[edge],edge});
            edgesCount[edge]-=1;
            nodes.insert({edgesCount[edge],edge});
        }
    }
    cout<<dp[n-1];
}