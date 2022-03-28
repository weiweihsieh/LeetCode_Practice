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
    bool hasCycle(ListNode *head)
    {
        // if list is empty or has only one node with no cycle
        if (!head || !head->next)
            return false;

        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;            
            
            // the list has cycle
            if (fast == slow || fast->next == slow)
                return true;
        }

        return false;
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

    bool result = sol.hasCycle(list);

    // output
    cout << result << endl;

    return 0;
}
