#include <iostream>

using namespace std;

// Definition for a binary tree node.
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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        // swap
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

int main()
{
    Solution sol;

    // input
    TreeNode input(1);
    input.left = new TreeNode(2);
    input.left->left = new TreeNode(3);
    input.right = new TreeNode(6);
    input.right->right = new TreeNode(4);

    sol.invertTree(&input);

    // output
    cout << input.left->val << endl;

    return 0;
}