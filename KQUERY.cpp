// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;    // for Policy Based DS
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

vector<int> graph[MAX_N];

long long dp[MAX_N];
long long dp2[MAX_N][5];


template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;


#define in_range(x, y, r, c) (x >= 0 && x < r && y >= 0 && y < c)
#define inp(arr) for(auto& x:arr) cin >> x
#define inpvp(arr) for(auto& x:arr) cin >> x.first >> x.second;
#define out(arr) for(auto x: arr) cout << x << ' '; cout << endl 
#define outvp(vp) for(auto x: vp) cout << '(' << x.first << "," << x.second << "), "; cout << endl;
# define f(a,n,i) for(int i = a; i<n; i++)
# define fe(a,n,i) for(int i = a; i<=n; i++)
# define fje(a,n,i,j) for(int i = a; i<=n; i+=j)
# define fn(n,a,i) for(int i = n; i>=a; i--)
# define fme(s,n,i,a) for(int i = s; i<=n; i*=a)
# define in(a) cin>>a
# define in2(a,b) cin>>a>>b
# define in3(a,b,c) cin>>a>>b>>c
# define in4(a,b,c,d) cin>>a>>b>>c>>d
# define ll long long
# define all(x) x.begin(), x.end()
# define sortall(x) sort(all(x))
# define npos string::npos
# define pii pair<int, int>
# define pll pair<ll,ll>
typedef pair<int,pair<int,int>> pipii;
typedef pair<int,string> pis;
typedef pair<string,string> pss;
# define vl vector<ll> 
# define vi vector<int>  
# define vpii vector<pii>
# define vpll vector<pll>
# define array_size(arr) (sizeof(arr) / sizeof(*(arr)))
# define mpq priority_queue<ll,vector<ll>,greater<ll>>
typedef set<int> si;
typedef set<pll> spll;
# define mul multiset<ll>
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef map<string,int> msi;
typedef map<char,int> mci;
# define memseti(array) memset(array, -1, sizeof(array));


ll c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;

/*/-----------------------------Code begins----------------------------------/*/

// GOOGLE
// void testcase(ll T) {cout << "Case #" << T << ": ";}



vector<vl>seg;
vector<ll> arr;

vector<ll> create(ll val){
    vector<ll> temp;
    temp.push_back(val);
    return temp;
}

vector<ll> combine(vector<ll> &a, vector<ll> &b){
    d = a.size();
    e = b.size();
    ll i = 0, j = 0;
    vector<ll>c;
    while(i<d && j<e){
        if(a[i]<=b[j]) c.push_back(a[i]), i++;
        else c.push_back(b[j]), j++;
    }

    while(i<d){
        c.push_back(a[i]);
        i++;
    }

    while(j<e){
        c.push_back(b[j]);
        j++;
    }

    return c;
}

 
// Building Operation
// time complexity: O(n)
// space complexity: O(n)
void build(int id = 1, int l = 0, int r = n){
    if(r-l==1){
        seg[id] = create(arr[l]);
        return;
    }

    int mid = (r+l)/2;
    build(2*id,l,mid);   // left child
    build(2*id+1,mid,r); // right child
    seg[id]=combine(seg[2*id],seg[2*id+1]);
}


// Querying Operation 
// Finds minimum in a range [x,y) or [x,y-1]
// Time complexity: O(log n)
ll query(int x, int y, int k, int id = 1, int l = 0, int r = n){
    if(l>=y || x>=r ) return 0;
    if(l>=x && r<=y) {
    return seg[id].size() - (upper_bound(seg[id].begin(),seg[id].end(),k) - seg[id].begin());
    }
    int mid = (r+l)/2;
    
    ll left = query(x,y,k,2*id,l,mid);
    ll right = query(x,y,k,2*id+1,mid,r);
    
    return left+right;
}

void solve(){
 
       in(n);

       arr.resize(n);
       seg.resize(4*n+1);

       f(0,n,i){
        cin>>arr[i];
       }

       in(q);
       build();

       while(q--){
        in3(i,j,k);
        cout << query(i-1,j,k) << endl;
       }

    
       fflush(stdout);
       cout << flush;
}



int main() {

    #ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif

ios_base::sync_with_stdio(0);
    cin.tie(0);

    
       solve();
       return 0;
}
