/* LeetCode 21 - Merge Two Sorted Lists */
/* by jennygaz */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode *head = nullptr;
  if( list1 and list2 ) {
    if( list1->val < list2->val ) {
      head = new ListNode(list1->val);
      list1 = list1->next;
    } else {
      head = new ListNode(list2->val);
      list2 = list2->next;
    }
  } else if( list1 ) {
    head = new ListNode(list1->val);
    list1 = list1->next;
  } else if( list2 ) {
    head = new ListNode(list2->val);
    list2 = list2->next;
  } else return head;
  ListNode *it = head;
  while( list1 and list2 ) {
    if( list1->val < list2->val ) {
      it->next = new ListNode(list1->val);
      list1 = list1->next;
    } else {
      it->next = new ListNode(list2->val);
      list2 = list2->next;
    }
    it = it->next;
  }
  while( list1 ) {
    it->next = new ListNode(list1->val);
    it = it->next;
    list1 = list1->next;
  }
  while( list2 ) {
    it->next = new ListNode(list2->val);
    it = it->next;
    list2 = list2->next;
  }
  return head;
}
