#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<int> prev(2,0),curr(2,0);
        prev[0]=prev[1]=0;
        int profit=0;
        for(int ind = n-1;ind>=0;ind--){
            for(int buy =0;buy<=1;buy++){
                if (buy) {
            profit = max(-prices[ind] + prev[0] ,  0 + prev[1]);
        } else {
            profit = max(prices[ind] + prev[1]-fee, 0 + prev[0]);
        }
         curr[buy]= profit;
        }
        prev = curr;
        }
        return prev[1];
    }
};


int main() {
    Solution solution;

    // Example usage:
    std::vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    int result = solution.maxProfit(prices, fee);

    std::cout << "Maximum Profit: " << result << std::endl;

    return 0;
}