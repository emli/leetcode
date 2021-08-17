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
    int getLen(ListNode* node){
        int len = 0;
        while(node != nullptr){
            node = node->next;
            len++;
        }
        return len;
    }
    ListNode* getSublist(ListNode* node,int left,int right){
        int len = getLen(node);

        ListNode* tmp = new ListNode(0);
        ListNode* ans = tmp;

        for(int i = 0; i < len; i++){

            if (left == i){
                ans->next = new ListNode(node->val);
                ans = ans->next;
            }
            if (i > left && i <= right){
                ans->next = new ListNode(node->val);
                ans = ans->next;
            }
            if (right == i){
                break;
            }

            node = node->next;
        }
        return tmp->next;
    } 
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = nullptr;

        while(head != nullptr){
            ListNode* next = head->next;
            head->next = ans;
            ans = head;
            head = next;
        }
        return ans;
    }
    ListNode* reverseBetween(ListNode* node, int left, int right) {
        left--;
        right--;
        ListNode* sublist = getSublist(node,left,right);
        ListNode* reversedList = reverseList(sublist);

        int len = getLen(node);

        ListNode* tmp = new ListNode(0);
        ListNode* ans = tmp;

        for(int i = 0; i < len; i++){
            if (i < left){
                ans->next = new ListNode(node->val);
                ans = ans->next;
            }
            if (i >= left && i <= right){
                ans->next = new ListNode(reversedList->val);
                ans = ans->next;
                reversedList = reversedList->next;
            }
            if (i > right){
                ans->next = new ListNode(node->val);
                ans = ans->next; 
            }
            node = node->next;
        }
    
    return tmp->next;
    }
};