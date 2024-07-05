class Solution {
public:
    int f(int ind,int n ,vector<int>&arr,int k ){
        if(ind ==n)return 0;
        int maxAns = INT_MIN;
        int len=0;
        int maxi=INT_MIN;
        for(int j =ind;j<min(n,ind+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum = maxi*len + f(j+1,n,arr,k);
            maxAns = max(maxAns,sum);
        }
        return maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        return f(0,n,arr,k);
        
    }
};