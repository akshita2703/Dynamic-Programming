#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

int fun(vector<int>&greed,vector<int>&s){
    int n = greed.size();
    int m = s.size();
    sort(greed.begin(),greed.end());
    sort(s.begin(),s.end());
    int i = 0,j = 0;
    int ans = 0;
    while(i<m && j<n){
        if(greed[j] <= s[i]) j++;
        i++;
    }
    return j;
}

void solve(){
    vector<int> greed = {1,5,3,3,4};
    vector<int> s = {4,2,1,2,1,3};
    int ans = fun(greed,s);
    cout << ans << endl;
    
}
int  main() {
    solve();
}