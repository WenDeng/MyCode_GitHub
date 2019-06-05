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
    char *Serialize(TreeNode *root) //将二叉树转换为字符串
    {   
        if(root==NULL) return NULL;
        string str;
        DoSerialize(str,root);
        char *ret=new char[str.length()];  
        str.copy(ret,str.length()-1,0);//拷贝字符串
        ret[str.length()-1]=='\0';
        return ret;
    }

    void DoDeserialize(TreeNode **node,char *str,int &index)
    {
        if(str[index]=='\0') return ;
        if(str[index]=='#')  //当前节点的左节点为空，直接返回。
        {
            index++;
            return ;
        }

        int value=0;
        while(str[index]>='0' && str[index]<='9')
        {
            value=value*10+str[index]-'0';
            index++;
        }
        *node=new TreeNode(value); //创建节点
        DoDeserialize(&((*node)->left),str,++index);
        DoDeserialize(&((*node)->right),str,++index);
    }
    TreeNode* Deserialize(char *str)
    { 
        //将字符串转换为二叉树
        TreeNode *root=NULL;
        if(!str) return root;
        int index=0;//用来记录字符串的下标
        DoDeserialize(&root, str, index);
        return root;
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

    TreeNode *ptr=NULL;

    cout<<solu.Serialize(p)<<endl;

    TreeNode *q=solu.Deserialize(solu.Serialize(p));
    cout<<endl<<solu.Serialize(q)<<endl;
    // string str="deng";
    // string &str1=str;
    // str1+=" wen";
    // cout<<str1<<endl;

}