#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp ;
        int l=1;
        temp.push_back(nums[0]);
        for(int i =0;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                l++;
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];        
            }
        }
        return l;
        
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