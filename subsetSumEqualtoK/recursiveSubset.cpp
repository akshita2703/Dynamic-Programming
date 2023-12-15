#include <bits/stdc++.h> 
using namespace std;

bool fun(int index , int target , vector<int>&arr){
    // base case
    if(target==0){
        return true;
    }
    if(index==0){
        return(arr[0]==target);
    }
    // explore all the possibilites
    bool notTaken = fun(index-1,target,arr);
    bool Taken = false;
    if(target>=arr[index]){
        Taken = fun(index-1,target-arr[index],arr);
    }
    return(Taken||notTaken);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {

    // Write your code here.
    return fun(n,k,arr);
}

int main() {
    
    vector<int> arr= {1,2,3,4};
    int k = 4;
    int n = 4;



    bool result = subsetSumToK(n,k,arr);
    cout << "subsetSum is  " << result <<endl;

    return 0;
}
