# 141.环形链表

## 考虑快慢指针

快慢指针的追赶问题，flow走一步，fast走两步结果会不会相遇？

flow走一步，fast走3步结果会不会相遇？

flow走一步，fast走4步结果会不会相遇？

................

- 使用快慢指针，当快指针进入环里的时候，相当于这要flow慢指针一旦进入环，快指针将会开始追赶，其实根据分析，flow走1步，fast走2步这样的步长是肯定可以追上的。
- 当追上时，那肯定就是有环了，当退出while循环了，说明当前链表不存在环路。

```c
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
```



这里问题其实就是一个数学追及问题。



- ？如何求出环的入口点`pos`?