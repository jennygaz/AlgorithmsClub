/* LeetCode 19 - Remove Nth Node From End of List */
/* by jennygaz */
ListNode* removeNthFromEnd(ListNode* head, int n) {
  if( not head ) return head;
  if( head and not head->next ) return nullptr;
  ListNode *it = head;
  int length {};
  while( it ) {
    it = it->next;
    ++ length;
  }
  int offset = length - n;
  it = head;
  if( offset == 0 ) return it->next;
  while( -- offset > 0 ) it = it->next;
  if( it->next ) {
    ListNode *new_next = it->next->next;
    ListNode *removable = it->next;
    removable->next = nullptr;
    it->next = new_next;
  } else it->next = nullptr;
  return head;
}
