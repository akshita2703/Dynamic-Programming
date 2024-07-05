 // https://www.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int fun(int e, int f , vector<vector<int>>&dp){   // recursive code + memoization 
        if(e==1) return f;
        if(f==0||f==1) return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int mini = INT_MAX;
        for(int i =1;i<=f;i++){
            int temp = 1+max(fun(e-1,i-1,dp),fun(e,f-i,dp));
            mini = min(mini,temp);
        }
        return dp[e][f] = mini;
    }
    int eggDrop(int n, int k) 
    { // tabulation
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int f = 2;f<=k;f++){
            dp[1][f] = f;
        }
        
        for(int e =2;e<=n;e++){
            dp[e][0] = 0;
            dp[e][1] = 1;
        }
        
        
        for(int e=2;e<=n;e++){
            for(int f = 2;f<=k;f++){
                int mini = INT_MAX;
                for(int i =1;i<=f;i++){
                    int temp = 1+max(dp[e-1][i-1],dp[e][f-i]);
                    mini = min(mini,temp);
                }
             dp[e][f] = mini;
                
            }
        }
        return dp[n][k];
        // your code here
    }
};