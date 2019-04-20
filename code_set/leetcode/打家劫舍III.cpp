#include<iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int max(int va,int vb){
        return va>=vb? va:vb;
    }
    
    int rob(TreeNode* root) {
        if(!root) return 0;
        if(!(root->left) && !(root->right)) return root->val;//没有儿子，则直接返回
           
        int result1=rob(root->left)+rob(root->right);//不取根节点  
        
        int result2=root->val;//取根节点
        if(root->left) result2+=rob(root->left->left)+rob(root->left->right);//左孙子 
        if(root->right) result2+=rob(root->right->left)+rob(root->right->right);
        
        return max(result1,result2);
    }
};

