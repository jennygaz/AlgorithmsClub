/* LeetCode 141 - Linked List Cycle I */
/* by jennygaz */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
  if( not head or not head->next ) return false;
  ListNode *tortoise = head, *hare = head;
  while( tortoise and hare ) {
    tortoise = tortoise->next;
    hare = hare->next;
    if( hare ) hare = hare->next;
    if( tortoise == hare ) break;
  }
  return hare != nullptr;
}
