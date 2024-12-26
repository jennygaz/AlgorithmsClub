/* LeetCode 23 - Merge K Sorted Lists */
/* by jennygaz */
#include <queue>
#include <vector>
#include <tuple>
#include <functional>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
  auto lambda = [](const ListNode *lhs, const ListNode *rhs) -> bool {
    if( lhs and rhs )
      return lhs->val != rhs->val ? lhs->val > rhs->val : lhs < rhs;
    return false;
  };
  std::priority_queue<ListNode*, std::vector<ListNode *>, decltype(lambda)> pq(lambda);
  std::vector<int> results {};
  results.reserve(10000);
  for( int i {}; i < lists.size(); ++ i ) {
    ListNode *tmp = lists[i];
    if( not tmp ) continue;
    pq.emplace(tmp);
  }
  while( not pq.empty() ) {
    ListNode *node = pq.top();
    pq.pop();
    if( not node ) continue;
    results.emplace_back(node->val);
    node = node->next;
    if( node ) pq.emplace( node );
  }
  ListNode *head = nullptr;
  if( results.size() == 0 ) return head;
  head = new ListNode(results.back(), nullptr);
  for( int i = results.size() - 2; i >= 0; -- i ) {
    ListNode *prev = new ListNode(results[i], head);
    head = prev;
  }
  return head;
}
