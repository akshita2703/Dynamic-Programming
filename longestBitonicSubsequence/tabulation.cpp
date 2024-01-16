class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    int n = nums.size();
        vector<int> dp1(n,1),dp2(n,1);
        int maxi=1;
        for(int i =0;i<n;i++){
            for(int j =0;j<i;j++){
                if(nums[i]>nums[j]&& dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
           
        }
         for(int i =n-1;i>=0;i--){
            for(int j =n-1;j>i;j--){
                if(nums[i]>nums[j]&& dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
           
        }
        int maxii=1;
        for(int i =0;i<n;i++){
            int sum = dp1[i]+dp2[i]-1;
            maxii=max(maxii,sum);

        }
       return maxii;
	}
};

