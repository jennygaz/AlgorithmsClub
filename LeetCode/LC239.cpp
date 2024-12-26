/* LeetCode 239 - Sliding Window Maximum */
/* by jennygaz */
#include <vector>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> results;
  results.reserve(nums.size() - k);
  deque<int> dq;
  for( int index {}; index < nums.size(); ++ index ) {
    while( not dq.empty() and dq.back() < nums[index] )
      dq.pop_back();
    dq.emplace_back(nums[index]);
    if( index >= k and nums[index - k] == dq.front() )
      dq.pop_front();
    if( index >= k - 1 )
      results.emplace_back(dq.front());
  }
  return std::move(results);
}
