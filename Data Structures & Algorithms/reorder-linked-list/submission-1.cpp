class Solution {
   public:
    void reorderList(ListNode* head) {  // find mid,split,reverse,merge
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;        // 1 step
            fast = fast->next->next;  // 2 steps
        }
        ListNode* firsthalf = head;
        ListNode* secondhalf = slow->next;
        slow->next = nullptr;
        ListNode* r = nullptr;
        ListNode* q = nullptr;
        ListNode* p = secondhalf;
        while (p != nullptr) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        secondhalf = q;
        ListNode* first = firsthalf;
        ListNode* second = secondhalf;
        while (second != nullptr) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};