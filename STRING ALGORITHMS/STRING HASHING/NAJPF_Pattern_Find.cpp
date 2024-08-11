
// हर हर महादेव
// जय महाकाल जय महाकाल जय महाकाल जय महाकाल
/* Author :- Himanshu Shekhar , IIIT Bhagalpur */

#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

#define ll long long 

ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,cnt,ans,maxi;
bool flag;
string str;


/*-----------------------------------------------------------------functions--------------------------------------------------------------*/


ll expo(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%MOD;
        a = (a * a)%MOD;
        b >>= 1;
    }
    return res%MOD;
}

vector<long long> p_pow;
vector<long long> inv_p_pow;
int P = 31;
void ComputePower() {
        
        
        int N = n;
        p_pow.resize(N, 1);
        for (int i = 1; i < N; i ++)
            p_pow[i] = (p_pow[i-1] * P) % MOD;
        
        inv_p_pow.resize(N, 1);
        
        inv_p_pow[N-1] = expo(p_pow[N-1], MOD-2);
        for (int i = N-2; i > 0; i --)
            inv_p_pow[i] = (inv_p_pow[i+1] * P) % MOD;

}


void solve(){


        
        string A, B;
        cin >> A >> B;

        if(A.length()<B.length()){
            // cout << 0 << endl;
            cout << "Not Found" << endl;
            cout << endl;
            return;
        }



        n = max(A.length(),B.length());

        ComputePower();

        int pattern_length = B.length();

        
        // Prefix Hashing the String RABIN KARP Algorithm
        vector<long long> hash_A(A.length()+1,0);

        for(int i = 0; i<A.length(); i++){
            hash_A[i+1] = (hash_A[i] + (A[i]-'a'+1)*p_pow[i])%MOD;
        }


        long long hash_B = 0;

        for(int i = 0; i< B.length(); i++){
            hash_B= (hash_B + (B[i]-'a'+1)*p_pow[i])%MOD;
        }

        vector<int> occurrences;

        for(int i = 0; i<=A.length()-pattern_length; i++){
           
            long long hash_value = (hash_A[i+pattern_length] + MOD - hash_A[i]) % MOD;
            
            if( hash_value == (hash_B*p_pow[i])%MOD){
                
                occurrences.push_back(i+1);
            }

        }


        if(occurrences.size()==0){
            cout << "Not Found" << endl;
            cout << endl;
        }
        else{
            cout << occurrences.size() << endl;
            for(int i = 0; i<occurrences.size(); i++){
                cout << occurrences[i] << " ";
            }
            cout << endl;
            cout << endl;
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
    cout.tie(NULL);

    cin >> t;
    for (int T = 1; T <= t; ++T)
    {
       
       solve();

    }

       return 0;
}


