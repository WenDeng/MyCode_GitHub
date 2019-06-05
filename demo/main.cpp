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
    // void DoSerialize(string &str,TreeNode *root)
    // {
    //     if(root==NULL) str+="#";
    //     DoSerialize(str,root->left);
    //     str+=root->val;
    //     DoSerialize(str,root->right);
    //     cout<<str;
    // }
    // char* Serialize(TreeNode *root)
    // {   //将二叉树转换为字符串
    //     string str;
    //     DoSerialize(str,root);

    //     str="dengwen";
    //     char *ret=new char[str.length()+1];
    //     str.copy(ret,str.length(),0);//拷贝字符串
    //     ret[str.length()]=='\0';
    //     return ret;
    // }

    // TreeNode* Deserialize(char *str)
    // { //将字符串转换为二叉树
    // }

    void midSearch(TreeNode *node, int &k, TreeNode **pp)
    {
        if (node == NULL) return;
        if(node->left) midSearch(node->left, k, pp);
        k--;
        if (k == 0) *pp = node;
        if(node->right) midSearch(node->right, k, pp);
    }
    TreeNode* KthNode(TreeNode *pRoot, int k)
    {
        if (pRoot == NULL) return NULL;
        TreeNode *ret;
        midSearch(pRoot, k, &ret);//获取指针变量的地址
        return ret;
    }
};

int gVar=4;
int *pVar=&gVar;
void setvalue(int **p)
{
    *p=pVar;
}

int main()
{
    Solution solu;
    TreeNode *p = new TreeNode(3);
    // cout<<solu.Serialize(p)<<endl;
    TreeNode *q=solu.KthNode(p,1);
    cout<<q->val<<endl;

    int **q1;
    setvalue(q1);
    cout<<**q1<<endl;


}