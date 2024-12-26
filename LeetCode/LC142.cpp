/* LeetCode 142 - Linked List Cycle II */
/* by jennygaz */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
  if( head == nullptr ) return head;
  if( head->next == nullptr ) return head->next;
  ListNode *slow = head;
  ListNode *fast = head;
  slow = head->next;
  fast = head->next->next;
  while( fast != nullptr and slow != fast ) {
    slow = slow->next;
    if( fast->next == nullptr ) return nullptr;
    fast = fast->next->next;
  }
  if( not fast or not slow ) return nullptr;
  while( head != slow ) {
    head = head->next;
    slow = slow->next;
  }
  return head;
}
