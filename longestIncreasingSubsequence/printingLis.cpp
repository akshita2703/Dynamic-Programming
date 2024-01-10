
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n,1),hash(n);
        int maxi=1,lastind=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[prev]<arr[i]&&1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastind = i;
            }
            
        }
        vector<int>temp;
        temp.push_back(arr[lastind]);
        while(hash[lastind]!=lastind){
            lastind=hash[lastind];
            temp.push_back(arr[lastind]);
        }
        
        reverse(temp.begin(),temp.end());
        return temp;
        
        // Code here
    }
};
int main() {
    

    Solution solution;
    
    // Example usage:
    std::vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> result = solution.longestIncreasingSubsequence(8,arr);
    for(auto it:result){
        cout<< it<<" ";
    }
  

    return 0;
}