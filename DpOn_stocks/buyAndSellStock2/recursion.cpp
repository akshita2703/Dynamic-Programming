#include <iostream>
#include <vector>

class Solution {
public:
    int fun(int ind, int buy, std::vector<int>& prices, int n) {
        if (ind == n) return 0;
        int profit = 0;
        if (buy) {
            profit = std::max(-prices[ind] + fun(ind + 1, 0, prices, n), 0 + fun(ind + 1, 1, prices, n));
        } else {
            profit = std::max(prices[ind] + fun(ind + 1, 1, prices, n), 0 + fun(ind + 1, 0, prices, n));
        }
        return profit;
    }

    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        return fun(0, 1, prices, n);
    }
};

int main() {
    Solution solution;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input, you can change it
    int result = solution.maxProfit(prices);
    std::cout << "Maximum Profit: " << result << std::endl;
    return 0;
}
