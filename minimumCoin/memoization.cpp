
//https://leetcode.com/problems/coin-change/
#include <bits/stdc++.h> 
using namespace std;


    int f(int ind,vector<int>& coins, int amount,vector<vector<int>> &dp)
    {
        if(ind==0){
           
            if(amount % coins[0]==0) return amount / coins[0];
            
            return 1e9; 
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int notTake = 0+f(ind-1,coins,amount,dp);
        int take = INT_MAX;
        if(coins[ind]<=amount){
            take = 1+f(ind,coins,amount-coins[ind],dp);
        }
        return min(notTake ,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        
        int ans =f(n-1,coins,amount,dp);
        if(ans>=1e9) return -1;
        return ans;
        
    }
int main(){
    vector<int> num = {411,412,413,414,415,416,417,418,419,420,421,422};
    int tar = 9864;
    cout<<coinChange(num,tar);
}