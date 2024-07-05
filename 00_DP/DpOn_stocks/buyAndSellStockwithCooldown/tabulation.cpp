#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<std::vector<int>> dp(n + 2, std::vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[ind][buy] = std::max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
                } else {
                    dp[ind][buy] = std::max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

int main() {
    Solution solution;
    // Example usage:
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    int maxProfit = solution.maxProfit(prices);
    
    std::cout << "Maximum Profit: " << maxProfit << std::endl;

    return 0;
}
