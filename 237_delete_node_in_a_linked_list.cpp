# include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void deleteNode(ListNode* node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
        
        /*
        ListNode *temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        temp->next = NULL;
        */
    }
};

int main()
{
    Solution sol;
    
    //input
    ListNode list(4);
    list.next = new ListNode(5);
    list.next->next = new ListNode(1);
    list.next->next->next = new ListNode(9);
    ListNode* node_delete = list.next; //given node

    sol.deleteNode(node_delete);

    //output
    ListNode* trace = &list;
    while(trace != nullptr)
    {
        cout << trace->val;
        trace = trace->next;
    }
    cout << endl;

    return 0;
}