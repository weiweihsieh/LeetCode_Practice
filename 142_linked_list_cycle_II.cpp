#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // if list is empty or has only one node with no cycle
        if (!head || !head->next)
            return NULL;

        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            // the list has cycle
            if (fast == slow)
            {
                // find the node which cycle begins
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};

int main()
{
    Solution sol;

    // input
    ListNode *list = new ListNode(3);
    list->next = new ListNode(2);
    ListNode *pos = list->next; // pos = 1
    list->next->next = new ListNode(0);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = pos;

    ListNode *result = sol.detectCycle(list);

    // output
    // return the node where the cycle begins
    cout << result->val << endl;

    return 0;
}