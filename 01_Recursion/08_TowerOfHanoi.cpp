#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
using ll = long long;

void solve(int n, int s ,int d ,int h){

    if(n==1){
        cout << " move plate n from s to d\n";
        return ;
    }
    solve(n-1,s,h,d);
    cout<< "moving n from s to d\n";
    solve(n-1,h,d,s);
}
int  main() {
    int n;
    cin>>n;
    int s =1;
    int h = 2;
    int d = 3;
    solve(n,s,d,h);
}