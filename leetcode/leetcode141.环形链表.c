/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode * flow = head;
    struct ListNode * fast = head;
    
    while(fast && fast->next){
        flow = flow->next;
        fast = fast->next->next;
        if(fast == flow){
            return true;
        }
    }
    return false;
}