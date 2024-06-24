#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

// void fun(int i , int n, vector<vector<int>>& res, vector<int> temp,vector<int>&nums){
//     if(i>=n){
//         res.push_back(temp);
//         return;
//     }
//     fun(i+1,n,res,temp,nums);
//     temp.push_back(nums[i]);
//     fun(i+1,n,res,temp,nums);
//     temp.pop_back();

// }

// vector<vector<int>> subsets(vector<int>& nums) {
//     int n = nums.size();
//     vector<vector<int>> res;
//     vector<int> temp;
//     fun(0,n,res,temp,nums);
//     return res;

        
// }

// void solve(){
//     int n;
//     cin>>n;
//     vector<int> nums(n);for(auto &x:nums)cin>>x;
//     vector<vector<int>> ans = subsets(nums);
//     for(auto &subset:ans){
//         cout<<"[";
//         for(auto &t:subset){
//             cout<<t<<" ";
//         }
//         cout<<"]";
//         cout<<endl;
//     }
// }
// int  main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n;
//     cin>>n;
//     while(n--){
//         solve();
//     }
   
// }




void solve(string ip,string op){
    if(ip.size()==0){
        cout<<op<<", ";
        return;
    }
    string op1 = op;
    string op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);

    solve(ip,op1);
    solve(ip,op2);
}

int main(){
    string ip ="abc";
    string op ="";
    solve(ip,op);
}







