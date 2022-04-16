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
    bool isPalindrome(ListNode *head)
    {
        // only has one node
        if (!head->next)
            return true;

        struct ListNode *slow = head, *fast = head;
        // when the loop stops, slow will point to the middle
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse back list
        slow->next = reverseList(slow->next);
        slow = slow->next;

        // compare front and back list
        while (slow)
        {
            if (head->val != slow->val)
                return false;

            head = head->next;
            slow = slow->next;
        }

        return true;
    }

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
    list->next->next = new ListNode(6);
    list->next->next->next = new ListNode(1);

    bool result = sol.isPalindrome(list);

    // output
    cout << result << endl;

    return 0;
}