/* LeetCode 445 - Add Two Numbers II */
/* by jennygaz */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  stack<int> result {};
  stack<int> lhs {}, rhs {};
  ListNode *it = l1;
  while( it ) {
    lhs.push(it->val);
    it = it->next;
  }
  it = l2;
  while( it ) {
    rhs.push(it->val);
    it = it->next;
  }
  int carry = 0;
  while( not lhs.empty() and not rhs.empty() ) {
    const int lhs_digit = lhs.top();
    lhs.pop();
    const int rhs_digit = rhs.top();
    rhs.pop();
    const int tmp_sum = lhs_digit + rhs_digit + carry;
    if( tmp_sum >= 10 ) carry = 1;
    else carry = 0;
    result.push(tmp_sum % 10);
  }
  while( not lhs.empty() ) {
    const int lhs_digit = lhs.top();
    lhs.pop();
    const int tmp_sum = lhs_digit + carry;
    if( tmp_sum >= 10 ) carry = 1;
    else carry = 0;
    result.push(tmp_sum % 10);
  }
  while( not rhs.empty() ) {
    const int rhs_digit = rhs.top();
    rhs.pop();
    const int tmp_sum = rhs_digit + carry;
    if( tmp_sum >= 10 ) carry = 1;
    else carry = 0;
    result.push(tmp_sum % 10);
  }
  if( carry ) result.push(carry);
  ListNode *new_head = new ListNode(result.top(), nullptr);
  result.pop();
  it = new_head;
  while( not result.empty() ) {
    const int digit = result.top();
    result.pop();
    it->next = new ListNode(digit, nullptr);
    it = it->next;
  }
  return new_head;
}
