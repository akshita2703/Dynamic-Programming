#include<bits/stdc++.h>
using namespace std;

void print(int n){
    // base condition
    if(n==1){ cout<< 1 << " ";return ;}
    print(n-1);
    cout<<n << " ";
}

int main(){

    int n;
    cout<<"Enter the number till where you want to print the number ";
    cin>>n;
    print(n);
    return 0;
}