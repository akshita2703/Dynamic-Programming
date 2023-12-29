

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int fun(int ind, int buy, vector<int>& prices, int n,vector<vector<int>>&dp) {
        if (ind == n) return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + fun(ind + 1, 0, prices, n,dp), 0 + fun(ind + 1, 1, prices, n,dp));
        } else {
            profit = max(prices[ind] + fun(ind + 1, 1, prices, n,dp), 0 + fun(ind + 1, 0, prices, n,dp));
        }
        return dp[ind][buy]= profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fun(0, 1, prices, n,dp);
    }
};

int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input, you can change it
    int result = solution.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}
