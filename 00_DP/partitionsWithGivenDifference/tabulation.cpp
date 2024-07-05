#include <bits/stdc++.h> 
using namespace std;


int findWays(vector<int>&num,int tar){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
 
    if(num[0]==0)dp[0][0]=2;
    else{dp[0][0]=1;}
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]]=1;
    for(int ind =1;ind<n;ind++){
        for( int sum =0;sum<=tar;sum++){
            int notTake = dp[ind-1][sum];
            int take = 0;
            if(num[ind]<=sum) take = dp[ind-1][sum-num[ind]];
            dp[ind][sum]=(notTake+take)%(1000000007);
        }
    }


    return dp[n-1][tar];

}
int countPartitions(int n, int d,vector<int>&num){
    int totSum=0;
    for(auto it:num){
        totSum+=it;
    }
    if(totSum-d<0||(totSum -d)%2) return false;
    return findWays(num,(totSum-d)/2);
}
int main(){
    vector<int> num = {5,2,6,4};
    int d = 3;
    int n = 4;
    cout<< countPartitions(n,d,num);
}


// T C 