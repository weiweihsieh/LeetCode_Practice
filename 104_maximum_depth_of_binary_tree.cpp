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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        if (leftDepth >= rightDepth)
            return leftDepth + 1;
        else
            return rightDepth + 1;
    }
};

int main()
{
    Solution sol;

    // input
    TreeNode input(1);
    input.right = new TreeNode(2);
    input.right->left = new TreeNode(3);

    int ans = sol.maxDepth(&input);

    // output
    cout << ans << endl;

    return 0;
}