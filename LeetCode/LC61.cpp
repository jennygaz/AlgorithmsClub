/* LeetCode 61 - Rotate List */
/* by jennygaz */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

int length_for(ListNode* head) {
  int length {};
  while( head ) {
    head = head->next;
    ++ length;
  }
  return length;
}

ListNode* rotateRight(ListNode* head, int k) {
  if( not head ) return head;
  int length = length_for(head);
  k %= length;
  if( k == 0 ) return head;
  int offset = length - k;
  ListNode *it = head;
  while( -- offset > 0 ) it = it->next;
  ListNode *new_head = it->next;
  it->next = nullptr;
  ListNode *tail = new_head;
  while( tail and tail->next ) tail = tail->next;
  tail->next = head;
  return new_head;
}
