// https://cses.fi/problemset/task/1634
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;



void solve(){
    int n;cin>>n;
    int x ;cin>>x;
    vector<int> coins(n,0);
    for(auto &it : coins)cin>>it;
    vector<int> dp(x+1,1e8);
    for(int i =0;i<=x;i++){dp[i]=1e8;}

    dp[0]=0;

    for(int i =1;i<=n;i++){
        for(int weight=0;weight<=x;weight++){
            if(weight - coins[i-1]>=0){
                dp[weight] = min(dp[weight],dp[weight-coins[i-1]]+1);
            }
        }
    }

    cout<<(dp[x]==1e8?-1:dp[x])<<endl;
}
int  main() {
    solve();
}