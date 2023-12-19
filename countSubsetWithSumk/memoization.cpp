#include <bits/stdc++.h> 
using namespace std;

int f(int ind , int sum , vector<int> &num,vector<vector<int>> &dp){
    if(sum==0) return 1;
    if(ind==0) return num[0]==sum;
    if(dp[ind][sum]!=-1){
        return dp[ind][sum];
    }
    
    int notTake = f(ind-1,sum,num,dp);
    int take = 0;
    if(num[ind]<=sum){
        take = f(ind-1,sum-num[ind],num,dp);
    }
    return dp[ind][sum]=take + notTake;

}
int findWays(vector<int>&num,int tar){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return f(n-1,tar,num,dp);

}
int main(){
    vector<int> num = {1,2,3};
    int tar = 3;
    cout<< findWays(num,tar);
}

// T.C - O(N X Sum)
// S.C - O(N XSum) +O(N)