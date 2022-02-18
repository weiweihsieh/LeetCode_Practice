#include <iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if(root->left == nullptr && root->right == nullptr) //only root
            return true;
        
        if(root->left && root->right && root->left->val == root->right->val) //compare left and right subtree
            return compare(root->left, root->right);
        else //values of nodes are different
            return false;
    }

private:
    int compare(TreeNode* treeLeft, TreeNode* treeRight)
    {
        if(treeLeft == nullptr && treeRight == nullptr) //complete check
            return true;

        if(treeLeft == nullptr || treeRight == nullptr) //one subtree is null
            return false;

        if(treeLeft->val != treeRight->val) //different values
            return false;
        else
            return compare(treeLeft->left, treeRight->right) && compare(treeLeft->right, treeRight->left);
    }
};

int main()
{
    Solution sol;
    
    //input
    TreeNode input(1);
    input.left = new TreeNode(2);
    input.left->left = new TreeNode(3);
    input.right = new TreeNode(2);
    input.right->right =  new TreeNode(4);

    bool ans = sol.isSymmetric(&input);
    
    //output
    cout << ans << endl;

    return 0;
}