#include<bits/stdc++.h>
using namespace std;
 
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0),left(nullptr),right(nullptr){}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
    TreeNode(int x , TreeNode* left,TreeNode* right) : val(x),left(left),right(right){}

};

int height(TreeNode* root){
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}
// input in the binsry tree
TreeNode* takeInput(){
    int val;
    cout<< "Enter the value of the node(Enter -1 for null)";
    cin>>val;
    if(val==-1){
        return nullptr;
    }
    TreeNode* root = new TreeNode(val);
    cout<<"Enter left child of "<<val<<":\n";
    root->left = takeInput();
    cout<<"Enter right child of "<<val<<":\n";
    root->right = takeInput();
    return root;


}

void inorderTraversal(TreeNode* root){
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}

int main(){
    TreeNode* root = takeInput();
    cout<<"Inorder Traversal of the binary search";
    inorderTraversal(root);
    cout<<endl;
    cout<<height(root);
    return 0;
}