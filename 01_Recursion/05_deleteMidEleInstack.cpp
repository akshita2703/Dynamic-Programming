// https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1

#include<bits/stdc++.h>
using namespace std;


void solve(stack<int>&s , int k){
    if(k==1){s.pop(); return ;}
    int val = s.top();
    s.pop();
    solve(s,k-1);
    s.push(val);
    return ;
}
void deleteMid(stack<int>&s, int sizeOfStack)
{
    if(sizeOfStack==0)return ;
    int k = sizeOfStack/2 +1;
    solve(s,k);
    return ;
         
}


int main(){

    stack<int> st ;
    st.push(8);
    st.push(2);
    st.push(3); 
    st.push(4);
    st.push(6);
    st.push(7);

    int n = 6;
    deleteMid(st,n);
    while(!st.empty()){
        cout<< st.top() << " ";
        st.pop();
    }
    return 0;
}