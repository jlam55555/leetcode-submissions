/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// This cheats a little by setting the value
// of the element to an unlikely value. A little
// more robust method is to set the next value
// to a known node, and check that instead of
// val. Both of these modify the array, however,
// so hash table/two pointers may be better.
#define FOUND -12351231
bool hasCycle(struct ListNode *head) {
    while(head) {
        if(head->val == FOUND)
            return true;
        head->val = FOUND;
        head = head->next;
    }
    return false;
}
