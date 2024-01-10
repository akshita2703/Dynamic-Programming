#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi =1;
        for(int ind = 0;ind<n;ind++){
            for(int prev=0;prev<ind;prev++){
                if(nums[prev]<nums[ind]){
                    dp[ind]=max(1+dp[prev],dp[ind]);
                }
            }
            maxi=max(maxi,dp[ind]);
        }
        return maxi;
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