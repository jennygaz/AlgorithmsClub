/* LeetCode 82 - Remove Duplicates From Sorted List II */
/* by jennygaz */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
  if( not head or not head->next ) return head;
  ListNode *prev = new ListNode(0, head);
  ListNode *new_head = prev, *curr = head;
  while( curr ) {
    if( curr->next and curr->val == curr->next->val ) {
      while( curr->next and curr->val == curr->next->val ) curr = curr->next;
      prev->next = curr->next;
    } else prev = curr;
    curr = curr->next;
  }
  return new_head->next;
}
