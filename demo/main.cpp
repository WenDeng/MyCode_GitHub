#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <list>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

class Solution
{
public:
    void DoSerialize(string &str,TreeNode *root)
    {
        if(root==NULL) {str+="#,";return;}
        if(root) str += to_string(root->val) + ",";
        DoSerialize(str,root->left);
        DoSerialize(str,root->right);
    }
    char* Serialize(TreeNode *root)
    {   //将二叉树转换为字符串
        string str;
        DoSerialize(str,root);
        char *ret=new char[str.length()];  
        str.copy(ret,str.length()-1,0);//拷贝字符串
        ret[str.length()-1]=='\0';
        return ret;
    }

    TreeNode* Deserialize(char *str)
    { 
        //将字符串转换为二叉树
    }
};



int main()
{
    Solution solu;
    TreeNode *p = new TreeNode(11);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(6);
    TreeNode *node4 = new TreeNode(16);
    p->left=node3;
    p->left->left=node2;
    p->left->left->left=node1;
    p->right=node4;

    cout<<solu.Serialize(p)<<endl;

    TreeNode *q=solu.Deserialize(solu.Serialize(p));
    cout<<solu.Serialize(q)<<endl;
    // string str="deng";
    // string &str1=str;
    // str1+=" wen";
    // cout<<str1<<endl;

}