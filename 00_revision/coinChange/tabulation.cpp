#include<bits/stdc++.h>
using namespace std;

// [1 , 2, 3] amount =11;

// [
//    1 []
//    2 []
//    3 []
// ]


int coinChange(vector<int>&coins , int amount){
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,1e8));

    for(int tar =0;tar<n;tar++){
        if(tar%coins[0]==0){
            dp[0][tar] = tar/coins[0];
        }
    }
    for(int ind = 1;ind<n;ind++){
        for(int tar =0;tar<=amount;tar++){
            
            int notTake = 0+dp[ind-1][tar];
            int take = INT_MAX;
            if(tar>=coins[ind]){
                take = 1+dp[ind][tar-coins[ind]];
            }
            dp[ind][tar] = min(take,notTake);
        }
    }
    return dp[n-1][amount];


}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n ;
        cin>>n;
        vector<int>coins;
        for(int i =0;i<n;i++){
            int k;
            cin>>k;
            coins.push_back(k);
        }
        int amount;
        cin>> amount;

        int ans = coinChange(coins,amount);
        cout<< ans;
    }
    return 0;
}