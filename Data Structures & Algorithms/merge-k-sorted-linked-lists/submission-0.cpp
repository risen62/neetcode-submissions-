/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return mergeKListsHelper(lists,0,lists.size() - 1);
    }

    private:
    ListNode* mergeKListsHelper(vector<ListNode*>& lists,int start,int end){
        if(start == end) return lists[start];
        if(start + 1 == end) return mergeLists(lists[start],lists[end]);
        int mid = start + (end - start) / 2;
        ListNode *left = mergeKListsHelper(lists,start,mid);
        ListNode *right = mergeKListsHelper(lists,mid + 1,end);
        return mergeLists(left,right);


    }
    ListNode* mergeLists(ListNode *l1,ListNode *l2){
        ListNode dummy(0);
        ListNode *curr = &dummy;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1 != nullptr){
            curr->next = l1;
        }else{
            curr->next = l2;
        }
        return dummy.next;
    }
};