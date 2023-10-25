// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

// -------------------------------------------------------------------------------------FENWICK TREE / BIT ---------------------------------------------------------------------------------

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;    // for Policy Based DS
const int MOD = 1e9 + 7;
const long long INF = 1e15;
const int MAX_N = 200 * 1000 + 13;
const int MAX1 = 1e6+10;
long long n, q, x;

vector<int> graph[MAX_N];

long long dp[MAX_N];
long long dp2[MAX_N][5];

using namespace std;

// USING FENWICK TREE / BIT

long long bit[MAX_N], pos[MAX1], ans[MAX_N], a[MAX_N];
pair<long long, pair<long long, long long>> pr[MAX_N];

void update(long long idx, long long val) {
    while (idx < MAX_N) {     // MAX_N bcoz jo range declare hain array so last tak jana hainb
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

long long query(long long idx) {
    long long sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int  main() {



     #ifndef ONLINE_JUDGE
//for getting input from input.txt
freopen("input1.txt", "r", stdin);
//for writing output to output.txt
freopen("output.txt", "w", stdout);
#endif

    
    cin >> n;
    for (long long i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    cin >> q;

    // OFFLINE QUERIES
    for (long long i = 0; i < q; ++i) {
        cin >> pr[i].second.first >> pr[i].first;
        pr[i].second.second = i;
    }

    sort(pr, pr + q);   // sorting on incresing value of r;
    
    memset(pos, -1, sizeof(pos)); // at the beginning every index is -1;
    memset(bit, 0, sizeof(bit));
    x = 0;
    for (long long i = 1; i <= n; ++i) {
        if (pos[a[i]] != -1) 
        update(pos[a[i]], -1);  // decrement at old position
        pos[a[i]] = i; // new position
        update(i, 1); // update at new position

        // iterating from 1 to n and checking only for r == i
        while (x < q && pr[x].first == i) {
            ans[pr[x].second.second] = query(pr[x].first) - query(pr[x].second.first - 1);
            x++;
        }
    }

    for (long long i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}



