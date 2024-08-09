#include <bits/stdc++.h>
using namespace std;

int main() {
	
	while(true){
		
		string s;
		cin >> s;
		if(s=="*") break;
		int n = s.length();
		vector<int> lps(n,0);
		
		int i = 1, len = 0;
		
		while(i<n){
			if(s[i]==s[len]){
				len++;
				lps[i]=len;
				i++;
			}
			else{
				if(len>0){
					len = lps[len-1];
				}
				else{
					i++;
				}
			}
		}
		
		int lps_max = lps[n-1];
		
		if(n%(n-lps_max)==0){
			cout << n/(n-lps_max) << endl;
		}
		else{
			cout << 1 << endl;
		}
	}

	return 0;
}
