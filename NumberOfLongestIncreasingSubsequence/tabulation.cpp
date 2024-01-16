#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi= 1;
        vector<int> dp(n,1),count(n,1);
        for(int i =0;i<n;i++){
            for(int j =0;j<i;j++){
                if(nums[i]>nums[j]&& dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if(nums[i]>nums[j]&&dp[i]==dp[j]+1){
                        count[i] +=count[j];
                }
                
            }
            maxi = max(maxi,dp[i]);
           
        }
        int nos =0;
        for(int i =0;i<n;i++){
            if(dp[i]==maxi)nos+=count[i];
        }
        return nos;

        
    }
};

int main() {
    // Example usage:
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution solution;
    int result = solution.findNumberOfLIS(nums);

    cout << "Number of Longest Increasing Subsequences: " << result << endl;

    return 0;
}