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
    ListNode *deleteMiddle(ListNode *head)
    {
        // if list is empty or has only one node
        if (!head || !head->next)
            return NULL;

        ListNode *slow = head, *fast = head->next->next;

        // when the loop stops, slow will point to the previous node of middle
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // delete middle node
        slow->next = slow->next->next;

        return head;
    }
};

int main()
{
    Solution sol;

    // input
    ListNode *list = new ListNode(1);
    list->next = new ListNode(6);
    list->next->next = new ListNode(8);

    ListNode *result = sol.deleteMiddle(list);

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