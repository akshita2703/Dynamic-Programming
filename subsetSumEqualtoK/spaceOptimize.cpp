#include <bits/stdc++.h> 
using namespace std;



bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<bool> prev(k+1,0), curr(k+1,0);
    
        prev[0]=curr[0] = true;
        prev[arr[0]] = true;
        for(int index=1;index<n;index++){
            for(int target =1;target<=k;target++){
                bool notTaken = prev[target];
                bool taken = false;
                if(arr[index]<=target){
                    taken = prev[target-arr[index]];
                }
                curr[target] = taken|notTaken;
            }
            prev = curr;

        }

    
    return prev[k];
    
}

int main() {
    
    vector<int> arr= {1,2,3,4,5};
    int k = 4;
    int n = 5;



    bool result = subsetSumToK(n,k,arr);
    cout << "subsetSum is  " << result <<endl;

    return 0;
}
