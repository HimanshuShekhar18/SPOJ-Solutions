// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;

# define ll long long

vector<vector<ll>> graph(MAX_N);
vector<vector<ll>> graph2(MAX_N);

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;

vector<int> temp;
vector<ll> topo;
vector<bool> vis;

void dfs2(ll node){
  vis[node]=true;
  temp.push_back(node);
  for(auto v: graph2[node]){
    if(!vis[v]) dfs2(v);
  }
}
void dfs1(ll node){
  vis[node]=true;
  for(auto v: graph[node]){
    if(!vis[v]) dfs1(v);
  }

  topo.push_back(node);
}

void solve(){
    cnt=0;  // used for indexing the SCC
    cin>> n >> m;

    // 0-based indexing
    for(ll i=0;i<m;i++){
    ll x,y;
    cin>>x>>y;
    graph[x].push_back(y);  // original graph
    graph2[y].push_back(x); // graph with edges reversed
    }

    vis.assign(MAX_N, false);

    // step 1: Get the order of nodes in their finishing time
    for(ll i = 1; i<=n; i++){
      if(!vis[i]){
        dfs1(i);
    }
    }

    // operation is similar to stack operation
    // basically topo order will be like 5 4 3 2 1, but we want 1 2 3 4 5, so we reversed it
    reverse(topo.begin(),topo.end());
    
    vis.assign(MAX_N, false);

    vector<vector<int>> scc;
   

    // now traversing vertices according to "topo" vector
    for(ll i = 0; i<n; i++){
      if(!vis[topo[i]]){
         dfs2(topo[i]);
         scc.push_back(temp);
         temp.clear();
         cnt++;
      }
    }

    // sink node in topological order
    cout << scc[cnt-1].size() << endl;
    // sorting the sink node
    sort(scc[cnt-1].begin(),scc[cnt-1].end());

    for(auto it: scc[cnt-1]){
      cout << it << " ";
    }

  cout << endl; 

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

// time_t timetoday
//    time (&timetoday);
//    cout << asctime(localtime(&timetoday)) << endl;
//    // return 0;

ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);

     solve();
       return 0;
}
