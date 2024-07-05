

#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                profit+=prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};
int main() {
    Solution solution;
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example input, you can change it
    int result = solution.maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}