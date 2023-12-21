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

int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &wt){

    // Write Your Code Here.

    vector<int>prev(W+1,0),curr(W+1,0);
    for(int w=0;w<=W;w++){
        prev[w]= (w/wt[0])*val[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=W;w++){
            int notTake = prev[w];
            int take = INT_MIN;
            if(wt[ind]<=w){
                take = val[ind]+curr[w-wt[ind]];
            }
            curr[w]=max (notTake,take);
        }
        prev =curr;
        
    }

    return prev[W];


}
int main()
{
    vector<int> profit = {5,11,13};
    vector<int> wt= {2,4,6};
    int w = 10;
    int n = 3;
    cout<<unboundedKnapsack(n,w,profit,wt);
}