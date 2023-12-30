#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int f(int ind , int buy,int cap ,int n,vector<int>& prices){
        // base case
        if(ind ==n)return 0;
        if(cap==0)return 0;
        int profit =0;
        if(buy){
            return profit = max(-prices[ind]+f(ind+1,0,cap,n,prices),0+f(ind+1,1,cap,n,prices));
        }
        else{
            return profit = max(prices[ind]+f(ind+1,1,cap-1,n,prices),0+f(ind+1,0,cap,n,prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return f(0,1,2,n,prices);
        
    }
};
int main() {
    Solution solution;
    vector<int> prices = {3,3,5,0,0,3,1,4}; // Example input, you can change it
    int result = solution.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}