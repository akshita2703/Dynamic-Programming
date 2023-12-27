#include<bits/stdc++.h>
using namespace std;

// int Dist(int i , int j,string &s1, string &s2 ,vector<vector<int>> &dp){
//     if(i<0)return j+1;
//     if(j<0)return i+1;
//     if(dp[i][j]!=-1)return dp[i][j];
//     if(s1[i]==s2[j])return dp[i][j]= Dist(i-1,j-1,s1,s2,dp);
//     return dp[i][j]=1+min(Dist(i,j-1,s1,s2,dp),min(Dist(i-1,j-1,s1,s2,dp),Dist(i-1,j,s1,s2,dp)));

// }
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // base case
    for(int i =0;i<=n;i++){
        dp[i][0]=i;
    }
    for(int j =0;j<=m;j++){
        dp[0][j]=j;
    }
    for(int i =1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
    }


    return dp[n][m];
    
}
int main()
{
    string text1 ="babgbag";
    string text2= "bag";
    cout<< minDistance(text1,text2);
}