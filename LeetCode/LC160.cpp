/* LeetCode 160 - Intersection of Two Linked Lists */
/* by jennygaz */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  ListNode *lhs = headA;
  ListNode *rhs = headB;
  /* if no modification is available */
  int lhs_count {}, rhs_count {};
  while( lhs ) {
    lhs = lhs -> next;
    ++ lhs_count;
  }
  while( rhs ) {
    rhs = rhs -> next;
    ++ rhs_count;
  }
  lhs = headA;
  rhs = headB;
  while( lhs_count > rhs_count ) {
    lhs = lhs -> next;
    -- lhs_count;
  }
  while( rhs_count > lhs_count ) {
    rhs = rhs -> next;
    -- rhs_count;
  }
  while( lhs and rhs ) {
    if( lhs == rhs ) return lhs;
    lhs = lhs -> next;
    rhs = rhs -> next;
  }
  return rhs;
  /* If modification is valid:
     while( lhs ) {
     lhs -> val *= -1;
     lhs = lhs -> next;
     }
     while( rhs ) {
     if( rhs -> val < 0 ) break;
     rhs = rhs -> next;
     }
     lhs = headA;
     while( lhs ) {
     lhs -> val *= -1;
     lhs = lhs -> next;
     }
     return rhs;
  */
}
};
