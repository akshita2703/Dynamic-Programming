#include<bits/stdc++.h>
using namespace std;

int f(int ind , vector<int>&coins,int amount,vector<vector<int>> & dp){
    if(ind ==0) {
        if(amount%coins[0]==0)return amount/coins[0];
        return 1e8;
    }
    if(dp[ind][amount]!=-1)return dp[ind][amount];
    int notTake = 0+f(ind-1,coins,amount,dp);
    int take = INT_MAX;
    if(amount>=coins[ind]){
        take = 1+f(ind,coins,amount-coins[ind],dp);
    }
    return dp[ind][amount] = min(take,notTake);

}

int coinChange(vector<int>&coins,int amount){
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    return f(n-1,coins,amount,dp);
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