/* Author :- Himanshu Shekhar , IIIT Bhagalpur */
#include <bits/stdc++.h>
using namespace std;


# define f(a,n,i) for(int i = a; i<n; i++)
# define in2(a,b) cin>>a>>b


/*/-----------------------------Code begins----------------------------------/*/

// GOOGLE
// void testcase(ll T) {cout << "Case #" << T << ": ";}

vector<pair<int,int>> movements = {{-1,0},{1,0},{0,-1},{0,1}};
int level[1001][1001];


void solve(){

    int n,m;
    deque<pair<int,int>> q;

    in2(n,m);

    char matrix[n][m];

    f(0,n,i){
        f(0,m,j){
            cin >> matrix[i][j];
            level[i][j] = INT_MAX;
        }
    }


q.push_back({0,0});
level[0][0] = 0;

// time complexity: O(n*m)


    while(!q.empty()){
        int v_x = q.front().first;
        int v_y = q.front().second;
        q.pop_front();

        for(auto movement: movements){
            int child_x = movement.first + v_x;
            int child_y = movement.second + v_y;
            if(child_x<0 || child_y<0 || child_x>=n || child_y>=m) continue;

            if(matrix[child_x][child_y]==matrix[v_x][v_y] && level[child_x][child_y]>level[v_x][v_y]) {
                    q.push_front({child_x,child_y});
                    level[child_x][child_y] = level[v_x][v_y];
            }
               
            else if(matrix[child_x][child_y]!=matrix[v_x][v_y] && level[child_x][child_y]>level[v_x][v_y]+1) {
                 q.push_back({child_x,child_y});
                
                level[child_x][child_y] = level[v_x][v_y] + 1;
            }
        }
    }




   cout << level[n-1][m-1] << endl;


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
    int t;
    cin >> t;
    for (int T = 1; T <= t; ++T)
    {
       
       solve();

    }

       return 0;
}
