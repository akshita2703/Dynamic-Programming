#include <bits/stdc++.h> 
using namespace std;


int findWays(vector<int>&num,int tar){
    int n = num.size();
    vector<int> prev(tar+1,0),curr(tar+1,0);
 
    if(num[0]==0)prev[0]=2;
    else{prev[0]=1;}
    if(num[0]!=0 && num[0]<=tar) prev[num[0]]=1;
    for(int ind =1;ind<n;ind++){
        for( int sum =0;sum<=tar;sum++){
            int notTake = prev[sum];
            int take = 0;
            if(num[ind]<=sum) take = prev[sum-num[ind]];
            curr[sum]=(notTake+take)%(1000000007);
        }
        prev=curr;
    }


    return prev[tar];

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