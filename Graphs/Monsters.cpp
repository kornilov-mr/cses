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
ll playerCount=1;
vector<vector<char>> room;
vector<vector<char>> paths;
vector<pii> players;
vector<pii> monsters;
int n,m;
void printRoom(){
    f(i,0,n){
        f(j,0,m){
           cout<<paths[i][j];
        }
        cout<<"\n";
    }
    cout<<"--------------------"<<"\n";
}
bool monsterCheck(int i,int j){
    return (i>=0&&i<n&&j>=0&&j<m&&room[i][j]!='#'&&room[i][j]!='M');
}
bool playerCheck(int i,int j){
    return (room[i][j]!='#'&&room[i][j]!='M'&&room[i][j]!='A');
}
int main(){
    cin>>n>>m;
    room.resize(n);
    paths.resize(n);
    f(i,0,n){
        f(j,0,m){
            char a; cin>>a;
            room[i].push_back(a);
            paths[i].push_back('.');
            if(a=='A'){
                players.push_back({i,j});
                paths[i][j]='*';
            }else if(a=='M'){
                monsters.push_back({i,j});
            }
        }
    }
    int endi=-1;
    int endj=-1;
    vector<pii> newMonsters;
    vector<pii> newPlayers;
    int iterSize;
    while(playerCount>0&&!players.empty()){
        iterSize=players.size();
        f(i,0,iterSize){
            bool added= false;
            pii cords= players.back();
            players.pop_back();
            if(room[cords.first][cords.second]=='M'){
                continue;
            }
            if(cords.first==0||cords.first==n-1||cords.second==0||cords.second==m-1){
                endi=cords.first;
                endj=cords.second;
                playerCount=-1;
                break;
            }
            if(playerCheck(cords.first-1,cords.second)){
                playerCount+=1;
                room[cords.first-1][cords.second]='A';
                paths[cords.first-1][cords.second]='U';
                newPlayers.push_back({cords.first-1,cords.second});
                added=true;
            }
            if(playerCheck(cords.first+1,cords.second)){
                playerCount+=1;
                room[cords.first+1][cords.second]='A';
                paths[cords.first+1][cords.second]='D';
                newPlayers.push_back({cords.first+1,cords.second});
                added=true;
            }
            if(playerCheck(cords.first,cords.second+1)){
                playerCount+=1;
                room[cords.first][cords.second+1]='A';
                paths[cords.first][cords.second+1]='R';
                newPlayers.push_back({cords.first,cords.second+1});
                added=true;
            }
            if(playerCheck(cords.first,cords.second-1)){
                playerCount+=1;
                room[cords.first][cords.second-1]='A';
                paths[cords.first][cords.second-1]='L';
                newPlayers.push_back({cords.first,cords.second-1});
                added=true;
            }
            if(!added){
                playerCount-=1;
            }
        }
        iterSize=monsters.size();
        f(i,0, iterSize){
            pii cords= monsters.back();
            monsters.pop_back();
            if(monsterCheck(cords.first-1,cords.second)){
                if(room[cords.first-1][cords.second]=='A'){
                    playerCount-=1;
                }
                room[cords.first-1][cords.second]='M';
                newMonsters.push_back({cords.first-1,cords.second});
            }

            if(monsterCheck(cords.first+1,cords.second)){
                if(room[cords.first+1][cords.second]=='A'){
                    playerCount-=1;
                }
                room[cords.first+1][cords.second]='M';
                newMonsters.push_back({cords.first+1,cords.second});
            }
            if(monsterCheck(cords.first,cords.second-1)){
                if(room[cords.first][cords.second-1]=='A'){
                    playerCount-=1;
                }
                room[cords.first][cords.second-1]='M';
                newMonsters.push_back({cords.first,cords.second-1});
            }
            if(monsterCheck(cords.first,cords.second+1)){
                if(room[cords.first][cords.second+1]=='A'){
                    playerCount-=1;
                }
                room[cords.first][cords.second+1]='M';
                newMonsters.push_back({cords.first,cords.second+1});
            }
        }
        monsters=newMonsters;
        players=newPlayers;
        newMonsters.clear();
        newPlayers.clear();
//        printRoom();
    }
    if(endi==-1){
        cout<<"NO";
        return 0;
    }
    vector<char> ans;
    while(paths[endi][endj]!='*'){
        ans.push_back(paths[endi][endj]);
        if(paths[endi][endj]=='U'){
            endi++;
        }else if(paths[endi][endj]=='D'){
            endi--;
        }else if(paths[endi][endj]=='R'){
            endj--;
        }else if(paths[endi][endj]=='L'){
            endj++;
        }
    }
    cout<<"YES"<<"\n";
    cout<<ans.size()<<'\n';
    for(int i = ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }

}