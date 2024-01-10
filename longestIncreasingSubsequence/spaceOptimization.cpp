#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
 int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>curr(n+1,0),prev(n+1,0);
        for(int ind = n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
                int notTake = 0+prev[prev_ind+1];
                int take = 0;
            
                if(prev_ind==-1||nums[ind]>nums[prev_ind]){
                    take = 1+prev[ind+1];
                }
                int lent = max(notTake,take);
                curr[prev_ind+1] = lent;

            }
            prev=curr;
        }
        return prev[-1+1];
        
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