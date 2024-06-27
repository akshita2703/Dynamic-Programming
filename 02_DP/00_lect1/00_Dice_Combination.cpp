
// https://cses.fi/problemset/task/1633/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;
#define long long int  ;

int noofWays(int n , vector<int>&dp){
    if(n<0) return 0;
    if(n==0) return 1;

    if(dp[n]!=-1)return dp[n];
    dp[n] =0;
    for(int i =1;i<=6;i++){
        dp[n]=(dp[n]+noofWays(n-i,dp))%MOD;
    }
    return dp[n];
}

void solve(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<noofWays(n,dp);
}
int  main() {
    solve();
}