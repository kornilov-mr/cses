#include <bits/stdc++.h>
using namespace std;


/* Data Type  */
#define ll long long
#define pii pair<int, int>
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

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long double n; cin>>n;
    long double x1,x2,x3,x4,y1,y2,y3,y4;
    f(i,0,n){
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;


        if(x2-x1==0&&x4-x3==0){
            if(x1==x3) {
                if (min(y1, y2) > max(y3, y4)) {
                    cout << "NO" << endl;
                } else if (min(y3, y4) > max(y1, y2)) {
                    cout << "NO" << endl;
                } else {
                    cout << "YES" << endl;
                }
            }else{
                cout<<"NO"<<endl;
            }
            continue;
        }else if(x2-x1==0){
            long double k2 =(y4-y3)/(x4-x3);
            long double a2 =y3-x3*k2;
            long double x=x1;
            long double y=k2*x+a2;
            if(x>=min(x1,x2)&&x<=max(x1,x2)&&y>=min(y1,y2)&&y<=max(y1,y2)
               &&x>=min(x3,x4)&&x<=max(x3,x4)&&y>=min(y3,y4)&&y<=max(y3,y4)){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
            continue;
        }else if(x4-x3==0){
            long double k1 =(y2-y1)/(x2-x1);
            long double a1 =y1-x1*k1;
            long double x=x3;
            long double y=k1*x+a1;
            if(x>=min(x1,x2)&&x<=max(x1,x2)&&y>=min(y1,y2)&&y<=max(y1,y2)
               &&x>=min(x3,x4)&&x<=max(x3,x4)&&y>=min(y3,y4)&&y<=max(y3,y4)){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
            continue;
        }

        long double k1 =ceil((y2-y1)/(x2-x1) * 100000000000.0)/100000000000.0;
        long double k2 =ceil((y4-y3)/(x4-x3)*100000000000.0)/100000000000.0;
        long double a1 =y1-x1*k1;
        long double a2 =y3-x3*k2;
        if(std::ceil(k1 * 1000000.0) / 1000000.0==std::ceil(k2 * 1000000.0) / 1000000.0){
            if(a1!=a2){
                cout<<"NO"<<endl;
            }else{
                if(min(y1,y2)<=max(y3,y4)||max(y1,y2)>=min(y3,y4)){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"NO"<<endl;
                }
            }
            continue;
        }
        long double x=ceil((a2-a1)/(k1-k2)*100000000000.0)/100000000000.0;
        long double ypar1=ceil((k1*x+a1)*100000000000.0)/100000000000.0;
        if(x>=min(x1,x2)&&x<=max(x1,x2)&&ypar1>=min(y1,y2)&&ypar1<=max(y1,y2)
            &&x>=min(x3,x4)&&x<=max(x3,x4)&&ypar1>=min(y3,y4)&&ypar1<=max(y3,y4)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}