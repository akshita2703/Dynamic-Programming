#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int f(int ind,int prev_ind,vector<int>& nums,int n,vector<vector<int>> &dp){
        if(ind==n)return 0;
        if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
        int notTake = 0+f(ind+1,prev_ind,nums,n,dp);
        int take = 0;
     
        if(prev_ind==-1||nums[ind]>nums[prev_ind]){
            take = 1+f(ind+1,ind,nums,n,dp);
        }
        int lent = max(notTake,take);
        return dp[ind][prev_ind+1] = lent;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,n,dp);
        
    }
};
int main() {
    

    Solution solution;
    
    // Example usage:
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int result = solution.lengthOfLIS(nums);

    cout << "Length of Longest Increasing Subsequence: " << result << endl;

    return 0;
}