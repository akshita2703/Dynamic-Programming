#include <bits/stdc++.h> 
using namespace std;

int f(int ind , int sum , vector<int> &num,vector<vector<int>> &dp){
    
    if(ind==0){
      if (sum == 0 && num[0] == 0) {
        return 2;
      }
      if (sum == 0 || sum ==num[0] ) {
        return 1;
      }
      return 0;
    }
    if(dp[ind][sum]!=-1){
        return dp[ind][sum];
    }
    
    int notTake = f(ind-1,sum,num,dp);
    int take = 0;
    if(num[ind]<=sum){
        take = f(ind-1,sum-num[ind],num,dp);
    }
    return dp[ind][sum]=(take + notTake)% (1000000007);//Added a modulo operation in the return statement to handle large values

}
int findWays(vector<int>&num,int tar){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    return f(n-1,tar,num,dp);

}
int countPartitions(int n, int d,vector<int>&num){
    int totSum=0;
    for(auto it:num){
        totSum+=it;
    }
    if(totSum-d<0||(totSum -d)%2) return false;
    return findWays(num,(totSum-d)/2);
}
int main(){
    vector<int> num = {5,2,5,1};
    int d = 3;
    int n = 4;
    cout<< countPartitions(n,d,num);
}