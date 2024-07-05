#include <bits/stdc++.h> 
using namespace std;

int f(int ind , int sum , vector<int> &num){
    if(sum==0) return 1;
    if(ind==0) return num[0]==sum;
    
    int notTake = f(ind-1,sum,num);
    int take = 0;
    if(num[ind]<=sum){
        take = f(ind-1,sum-num[ind],num);
    }
    return take + notTake;

}
int findWays(vector<int>&num,int tar){
    int n = num.size();
    return f(n-1,tar,num);

}
int main(){
    vector<int> num = {1,2,3};
    int tar = 3;
    cout<< findWays(num,tar);
}


//T.c - O(2^n)
// S.C - O(N)