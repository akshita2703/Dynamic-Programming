class Solution {
public:
    int f(int ind,int n ,vector<int>&arr,int k , vector<int>&dp ){
        if(ind ==n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int maxAns = INT_MIN;
        int len=0;
        int maxi=INT_MIN;
        for(int j =ind;j<min(n,ind+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum = maxi*len + f(j+1,n,arr,k,dp);
            maxAns = max(maxAns,sum);
        }
        return dp[ind] = maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int maxAns = INT_MIN;
            int len=0;
            int maxi=INT_MIN;
            for(int j =i;j<min(n,i+k);j++){
                len++;
                maxi=max(maxi,arr[j]);
                int sum = maxi*len + dp[j+1];
                maxAns = max(maxAns,sum);
            }
            dp[i] = maxAns;
            

        }
        return dp[0];
        
    }
};