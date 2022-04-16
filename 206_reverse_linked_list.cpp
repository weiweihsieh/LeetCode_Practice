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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr, *current = head, *next;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;

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

    ListNode *result = sol.reverseList(list);

    // output
    ListNode *trace = result;
    while (trace != nullptr)
    {
        cout << trace->val;
        trace = trace->next;
    }
    cout << endl;

    return 0;
}