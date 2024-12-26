/* LeetCode 92 - Reverse Linked List II */
/* by jennygaz */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

inline ListNode *reverse_list(ListNode *prev) {
  if( not prev or not prev->next ) return prev;
  ListNode *curr = prev->next;
  ListNode *next = curr->next;
  while( curr ) {
    curr->next = prev;
    prev = curr;
    curr = next;
    if( next ) next = next->next;
  }
  return prev;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
  if( not head or not head->next ) return head;
  ListNode *head_prev = new ListNode(0, head);
  ListNode *prev = head_prev;
  right -= left;
  while( -- left ) prev = prev->next;
  ListNode *curr = prev->next;
  while( right -- ) {
    ListNode *next = curr->next;
    curr->next = next->next;
    next->next = prev->next;
    prev->next = next;
  }
  return head_prev->next;
}
