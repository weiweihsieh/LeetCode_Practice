#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head)
{
    while(head != nullptr)
    {
        cout << head->val;
        head = head->next;
    }
}

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = nullptr; //previous node of delete
        ListNode *delNode = nullptr;

        ListNode dummy(-1, head); //dummy node
        slow = &dummy;

        for(int i=0; i<n; i++)
            fast = fast->next;

        while(fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        delNode = slow->next;
        slow->next = delNode->next;
        delNode = NULL;

        return dummy.next;
    }
};

int main()
{
    Solution sol;
    
    //input
    ListNode a(1);
    a.next = new ListNode(6);
    a.next->next = new ListNode(8);

    ListNode* n = sol.removeNthFromEnd(&a, 2);

    //output
    printList(n);
    cout << endl;

    return 0;
}