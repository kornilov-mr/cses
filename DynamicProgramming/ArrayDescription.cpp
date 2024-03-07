#include <bits/stdc++.h>
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

int lower=1;
int high;
struct vectorWithDesctiption{
    vector<ll> arr;
    int lower;
    int high;
};
vectorWithDesctiption buildOneIteration(vectorWithDesctiption lastStep){
    vector<ll> arr(lastStep.arr.size()+2-(lastStep.high==high)-(lastStep.lower==lower));
    vectorWithDesctiption newStep={arr,lastStep.lower-1+(lastStep.lower==lower),lastStep.high+1-(lastStep.high==high)};
    f(i,0,newStep.high-newStep.lower+1){
        ll step=0;
        if(i+newStep.lower-1>=lastStep.lower){
            step+=lastStep.arr[i+newStep.lower-1-lastStep.lower];
        }
        if(i+newStep.lower<=lastStep.high &&i+newStep.lower>=lastStep.lower){
            step+=lastStep.arr[i+newStep.lower-lastStep.lower];
        }
        if(i+newStep.lower+1<=lastStep.high){
            step+=lastStep.arr[i+newStep.lower+1-lastStep.lower];
        }
        newStep.arr[i]=(step)%mod;
    }
    return newStep;
}

int main(){
    int n;
    cin>>n>>high;
    int description[n];
    int prev=-1;
    f(i,0,n){
        int a;
        cin>>a;
        if(abs(a-prev)>1&&a!=0&&prev!=0&&prev!=-1){
            cout<<0;
            return 0;
        }
        description[i]=a;
        prev=a;
    }
    ll dp=1;
    vector<ll> temp;
    f(i,0,high){
        temp.push_back(1);
    }
    vectorWithDesctiption start;
    f(i,0,n){
        if(description[i]==0){
            if(i==0){
                start={temp,1,high};
            }else{
                start=buildOneIteration(start);
            }
        }else{
            ll forIteration=0;
            if(i!=0){
                f(j,description[i]-1-start.lower,description[i]+2-start.lower){
                    if(j<start.arr.size()){
                        forIteration+=start.arr[j];
                        forIteration%=mod;
                    }
                }
                dp*=forIteration;
                dp%=mod;
            }
            vector<ll> temp1;
            temp1.push_back(1);
            start.arr=temp1;
            start.lower=description[i];
            start.high=description[i];
        }
    }
    if(description[n-1]==0){
        ll forIteration=0;
        f(i,0,start.high-start.lower+1){
            forIteration+=start.arr[i];
        }
        dp*=forIteration;
        dp%=mod;
    }
    cout<<dp;
}