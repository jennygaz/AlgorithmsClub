/* LeetCode 206 - Reverse Linked List */
/* by jennygaz */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
  if( not head or not head->next ) return head;
  ListNode *prev = nullptr, *curr = head, *next = head->next;
  while( curr ) {
    curr->next = prev;
    prev = curr;
    curr = next;
    if( next ) next = next->next;
  }
  return prev;
}
