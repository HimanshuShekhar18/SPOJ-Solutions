#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;



int vis[8][8];
int level[8][8];


vector<pair<int,int>> movements = {
    {-1,2},{1,2},
    {-1,-2},{1,-2},
    {2,1},{-2,1},
    {2,-1},{-2,-1}
};




int bfs(string source, string dest){
    int sourceX = source[0] - 'a';
    int sourceY = source[1] - '1';
    int destX = dest[0] - 'a';
    int destY = dest[1] - '1';
    queue<pair<int,int>> q;
    q.push({sourceX,sourceY});
    vis[sourceX][sourceY] = 1;
    level[sourceX][sourceY] = 0;
    while(!q.empty()){
        pair<int,int> v = q.front();
        int x = v.first, y = v.second;
        q.pop();
        for(auto movement: movements){
            int childX = x + movement.first;
            int childY = y + movement.second;
            if(childX<0 ||  childX >= 8 || childY<0 ||  childY >= 8) continue;
            if(!vis[childX][childY]){
                q.push({childX,childY});
                level[childX][childY] = level[x][y] + 1;
                vis[childX][childY] = 1;
            }
        }
        if(vis[destX][destY] == 1) break;
    }

    return level[destX][destY];
}


void reset(){
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            level[i][j] = 0;
            vis[i][j] = 0;
        }
    }
}

int main(){
	    #ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif



int t;
cin >> t;
while(t--){
    reset();
    string start, dest;
    cin >> start >> dest;
    cout << bfs(start,dest) << endl;
}



}


/* input
3
a1 h8
a1 c2
h8 c3
*/
/* output
6
1
4
*/

