#include<bits/stdc++.h>
using namespace std;

void insert(stack<int>&st,int temp){
    if(st.empty()|| st.top()<=temp){
        st.push(temp);
        return ;
    }
    int val = st.top();
    st.pop();
    insert(st,temp);
    st.push(val);
    return;
}
void sortst(stack<int>&st){
    if(st.size()==1)return;
    int temp = st.top();
    st.pop();
    sortst(st);
    insert(st,temp);
}

int main(){
    stack<int> st ;
    st.push(8);
    st.push(2);
    st.push(3); 
    st.push(4);
    st.push(6);
    sortst(st);
    while(!st.empty()){
        cout<< st.top() << " ";
        st.pop();
    }

    return 0;

}