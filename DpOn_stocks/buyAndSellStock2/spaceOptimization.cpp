

#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
     int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2,0),curr(2,0);
        prev[0]=prev[1]=0;
        int profit=0;
        for(int ind = n-1;ind>=0;ind--){
            for(int buy =0;buy<=1;buy++){
                if (buy) {
            profit = max(-prices[ind] + prev[0] ,  0 + prev[1]);
        } else {
            profit = max(prices[ind] + prev[1], 0 + prev[0]);
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
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input, you can change it
    int result = solution.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}