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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = nullptr, **sorted = &head;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                *sorted = list1;
                list1 = list1->next;
            }
            else
            {
                *sorted = list2;
                list2 = list2->next;
            }

            sorted = &((*sorted)->next);
        }

        *sorted = (list1 ? list1 : list2);

        return head;
    }
};

int main()
{
    Solution sol;

    // input
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *result = sol.mergeTwoLists(list1, list2);

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