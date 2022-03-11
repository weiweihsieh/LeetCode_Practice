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
    ListNode *swapPairs(ListNode *head)
    {
        // if list is empty or has only one node
        if (!head || !head->next)
            return head;

        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy, *curr = head, *next = head->next;

        while (curr && curr->next)
        {
            next = curr->next;

            prev->next = curr->next;
            curr->next = next->next;
            next->next = curr;

            prev = curr;
            curr = prev->next;
        }

        return dummy->next;
    }
};

int main()
{
    Solution sol;

    // input
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);

    ListNode *result = sol.swapPairs(list);

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