

#include <bits/stdc++.h> 
using namespace std;

 int f(int ind,vector<int>& coins, int amount,vector<vector<int>> &dp)
    {
        if(ind==0){
           return( amount%coins[0])==0;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int notTake =f(ind-1,coins,amount,dp);
        int take = 0;
        if(coins[ind]<=amount){
            take =f(ind,coins,amount-coins[ind],dp);
        }
        return notTake+take;
    }
    int change(int amount, vector<int>& coins) {
       
        int n = coins.size();
         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1,coins,amount,dp);
    }

int main()
{
    vector<int> num = {265,398,78,46,52};
    int tar = 7754;
    cout<<change(tar,num);
}