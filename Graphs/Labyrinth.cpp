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
vector<vector<char>> arr;
queue<pair<pii,vector<char>>> nodes;
vector<vector<int>> seen;
int istart, jstart, iend,jend;

int main(){
//    ifstream cin("../Tests/Labyrinth3.txt");
    int n,m;
    cin>>n>>m;
    arr.resize(n);
    seen.resize(n);
    f(i,0,n){
        f(j,0,m){
            char a; cin>>a;
            seen[i].push_back(0);
            if(a=='A'){
                istart=i;
                jstart=j;
                arr[i].push_back('#');
                continue;
            }
            if(a=='B'){
                iend=i;
                jend=j;
                arr[i].push_back('.');
                continue;
            }
            arr[i].push_back(a);
        }
    }
    vector<char> temp;
    seen[istart][jstart]=1;
    nodes.push(make_pair(make_pair(istart,jstart),temp));
    while(true){
        if(nodes.empty()){
            vector<char> temp;
            cout<<"NO";
            return 0;
        }
        pair<pii,vector<char>> data= nodes.front();
        nodes.pop();
        pii cords= data.first;
        vector<char> way= data.second;

        int i=cords.first;
        int j=cords.second;
        if(i==iend&&j==jend){
            cout<<"YES"<<endl<<way.size()<<endl;
            f(i,0,way.size()){
                cout<<way[i];
            }
            return 0;

        }
        way.push_back('.');
        if(i>=1&& arr[i-1][j]!='#'&& seen[i-1][j]!=1){
            seen[i-1][j]=+1;
            way.back()='U';
            nodes.push(make_pair(make_pair(i-1,j),way));
        }
        if(i<n-1&& arr[i+1][j]!='#' && seen[i+1][j]!=1){
            seen[i+1][j]=+1;
            way.back()='D';
            nodes.push(make_pair(make_pair(i+1,j),way));

        }
        if(j>=1&& arr[i][j-1]!='#'&& seen[i][j-1]!=1){
            seen[i][j-1]=+1;
            way.back()='L';
            nodes.push(make_pair(make_pair(i,j-1),way));

        }
        if(j<m-1&& arr[i][j+1]!='#' && seen[i][j+1]!=1){
            seen[i][j+1]=+1;
            way.back()='R';
            nodes.push(make_pair(make_pair(i,j+1),way));
        }
    }

}