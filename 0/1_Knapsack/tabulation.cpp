#include <bits/stdc++.h> 
using namespace std;

int knapsack(vector<int>&wt,vector<int>&val,int n,int maxWeight){
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
    for(int W=wt[0];W<=maxWeight;W++){
        dp[0][W]=val[0];
    }
    for(int ind =1;ind<n;ind++){
        for(int W=0;W<=maxWeight;W++)
        {
            int notTake = 0+dp[ind-1][W];
            int take = INT_MIN;
            if(wt[ind]<=W){
                take = val[ind]+dp[ind-1][W-wt[ind]];
            }
            dp[ind][W] =  max(notTake,take);
        }
        
    }
    return dp[n-1][maxWeight];
    
}
int main(){
    vector<int>weight={3,2,5};
    vector<int>value={30,40,50};
    int maxWeight = 6;
    int n =3;
    cout<< knapsack(weight,value, n, maxWeight);
}
