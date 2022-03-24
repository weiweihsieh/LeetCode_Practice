#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        // if list is empty or has only one node
        if (!head || !head->next)
            return head;

        ListNode *node = head;

        while (node)
        {
            while (node->next && node->val == node->next->val)
                node->next = node->next->next;

            node = node->next;
        }

        return head;
    }
};

int main()
{
    Solution sol;

    // input
    ListNode *list = new ListNode(1);
    list->next = new ListNode(1);
    list->next->next = new ListNode(1);

    ListNode *result = sol.deleteDuplicates(list);

    // output
    ListNode *trace = result;
    while (trace)
    {
        cout << trace->val;
        trace = trace->next;
    }
    cout << endl;

    return 0;
}