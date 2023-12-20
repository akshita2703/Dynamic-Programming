
//https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 
using namespace std;

int f(int ind,int W,vector<int>&weight,vector<int>&value, vector<vector<int>>&dp){
    //base case
    if(ind==0){
        if(weight[0]<=W){
            return value[0];
        }
        return 0;
    }
    if(dp[ind][W]!=-1)return dp[ind][W];
    int notTake = 0+f(ind-1,W,weight,value,dp);
    int take = INT_MIN;
    if(weight[ind]<=W){
        take = value[ind]+f(ind-1,W-weight[ind],weight,value,dp);
    }
    return dp[ind][W] =  max(notTake,take);
}
int knapsack(vector<int>&weight,vector<int>&value,int n,int maxWeight){
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    return f(n-1,maxWeight,weight,value,dp);
}
int main(){
    vector<int>weight={3,2,5};
    vector<int>value={30,40,50};
    int maxWeight = 6;
    int n =3;
    cout<< knapsack(weight,value, n, maxWeight);
}
