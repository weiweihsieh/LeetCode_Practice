#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;
        head = head->next;
    }
}

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(-1, head); // dummy node
        ListNode *fast = head, *slow = dummy;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // slow points to the previous node to be deleted
        slow->next = slow->next->next;

        return dummy->next;
    }
};

int main()
{
    Solution sol;

    // input
    ListNode *list = new ListNode(1);
    list->next = new ListNode(6);
    list->next->next = new ListNode(8);

    ListNode *result = sol.removeNthFromEnd(list, 2);

    // output
    printList(result);
    cout << endl;

    return 0;
}