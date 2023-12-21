#include<bits/stdc++.h>

using namespace std;
int f(int ind , int W,vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
    if(ind==0){
        return (W/wt[0])*val[0];
    }
    int notTake = 0+f(ind-1,W,val,wt,dp);
    int take = INT_MIN;
    if(dp[ind][W]!=-1)return dp[ind][W];
    if(wt[ind]<=W){
        take = val[ind]+f(ind,W-wt[ind],val,wt,dp);
    }
    return dp[ind][W]=max(notTake,take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    // Write Your Code Here.

    vector<vector<int>> dp(n,vector<int>(w+1,-1));

    return f(n-1,w,profit,weight,dp);


}
int main()
{
    vector<int> profit = {5,11,13};
    vector<int> wt= {2,4,6};
    int w = 10;
    int n = 3;
    cout<<unboundedKnapsack(n,w,profit,wt);
}