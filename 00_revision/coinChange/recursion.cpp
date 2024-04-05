
//https://leetcode.com/problems/coin-change/description/
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
#include<bits/stdc++.h>
using namespace std;

int f(int ind , vector<int>& coins, int amount){
    // base codition
    if(ind == 0){
        if(amount%coins[0] == 0) return amount/coins[0];
        return 1e8;
    }
    // take and not take 
    int notTake = 0+f(ind-1,coins,amount);
    int take = INT_MAX;
    if(amount>=coins[ind]){
        take = 1+f(ind,coins,amount-coins[ind]);
    }
    return min(take , notTake);

}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    return f(n-1,coins,amount);
        
    }

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> coins;
        for(int i =0;i<n;i++){
            int k ;
            cin>>k;
            coins.push_back(k);
        }
        int amount ;
        cin>> amount;
        int ans = coinChange(coins,amount);
        cout<< ans;

        
    }
    
    return 0;
}