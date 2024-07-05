#include<bits/stdc++.h>
using namespace std;

int f(int ind , int n,vector<int>&price,vector<vector<int>>&dp){
    if(ind==0) return(price[0]*n);
    if(dp[ind][n]!=-1)return dp[ind][n];

    int notTake = f(ind-1,n,price,dp);
    int take = INT_MIN;
    int rodlength = ind+1;
    if(rodlength<=n){
        take = price[ind] +f(ind , n-rodlength,price,dp);
    }
    return dp[ind][n]=max(notTake,take);

}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    int N=price.size();
    return f(N-1,n,price,dp);
}

int main(){
    vector<int> arr={3,5,8,9,10,17,17,20};
    int n=8;
   
    cout<<cutRod(arr,n);
}