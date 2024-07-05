#include <bits/stdc++.h> 
using namespace std;


int findWays(vector<int>&num,int tar){
    int n = num.size();
    vector<int> prev(tar+1,0),curr(tar+1);
 
   prev[0]=curr[0]=1;
    if(num[0]<=tar) prev[num[0]]=1;
    for(int ind =1;ind<n;ind++){
        for( int sum =0;sum<=tar;sum++){
            int notTake = prev[sum];
            int take = 0;
            if(num[ind]<=sum) take = prev[sum-num[ind]];
            curr[sum]=notTake+take;
        }
        prev=curr;
    }


    return prev[tar];

}
int main(){
    vector<int> num = {1,2,3};
    int tar = 3;
    cout<< findWays(num,tar);
}


// T C  O(N X sum)
// S.C O(N)