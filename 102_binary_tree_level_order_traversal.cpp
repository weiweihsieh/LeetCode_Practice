#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        
        if(root == nullptr)
            return result;

        q.push(root);

        while(!q.empty())
        {
            vector<int> tmp; //save current level nodes
            int levelNum = q.size(); //the number of node in current level

            for(int i=0; i<levelNum; i++)
            {
                TreeNode* node = q.front();
                
                if(node->left != nullptr)
                    q.push(node->left);

                if(node->right != nullptr)
                    q.push(node->right);             
                
                tmp.push_back(node->val);
                q.pop();
            }

            result.push_back(tmp);
        }

        return result;
    }
};

int main()
{
    Solution sol;

    //input
    TreeNode input(1);
    input.left = new TreeNode(2);
    input.right = new TreeNode(3);
    input.left->left = new TreeNode(4);
    input.left->right = new TreeNode(5);
    input.right->left = new TreeNode(6);
    input.right->right =  new TreeNode(7);

    vector<vector<int>> output = sol.levelOrder(&input);
    
    //output
    for(int i=0; i<output.size(); i++)
    {
        cout << "[";
        for(int j=0; j<output[i].size(); j++)
        {
            cout << output[i][j];
        }
        cout << "]";
    }
    cout << endl;

    return 0;
}