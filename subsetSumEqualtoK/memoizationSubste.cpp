#include <bits/stdc++.h> 
using namespace std;

bool fun(int index , int target , vector<int>&arr, vector<vector<int>>&dp){
    // base case
    if(target==0){
        return true;
    }
    if(index==0){
        return(arr[0]==target);
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }
    // explore all the possibilites
    bool notTaken = fun(index-1,target,arr,dp);
    bool Taken = false;
    if(target>=arr[index]){
        Taken = fun(index-1,target-arr[index],arr,dp);
    }
    return dp[index][target] = Taken|notTaken;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {

    // Write your code here.
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return fun(n-1,k,arr,dp);
}

int main() {
    
    vector<int> arr= {1,2,3,4,5};
    int k = 4;
    int n = 5;



    bool result = subsetSumToK(n,k,arr);
    cout << "subsetSum is  " << result <<endl;

    return 0;
}
