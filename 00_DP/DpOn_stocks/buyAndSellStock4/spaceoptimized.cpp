#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
       
    int maxProfit(int k ,vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after (2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                        int profit =0;
                        if(buy){
                            curr[buy][cap]= max(-prices[ind]+after[0][cap],0+after[1][cap]);
                        }
                        else{
                            curr[buy][cap] = max(prices[ind]+after[1][cap-1],0+after[0][cap]);
                        }
                        //dp[ind][buy][cap]=profit;
                    
                }
            }
            after=curr;
        }

     return after[1][k];
        
    }
};
int main() {
    Solution solution;
    vector<int> prices = {3,3,5,0,0,3,1,4}; // Example input, you can change it
    int result = solution.maxProfit(4,prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}