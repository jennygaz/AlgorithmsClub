/* LeetCode 703 - Kth Largest Element in a Stream */
/* by jennygaz */
class KthLargest {
private:
  int K;
  priority_queue<int, std::vector<int>, std::greater<int>> pq;
public:
  KthLargest(int k, vector<int>& nums) : pq(nums.begin(), nums.end()), K(k) {
    while( pq.size() > k ) pq.pop();
  }
    
  int add(int val) {
    pq.emplace(val);
    if( pq.size() > K ) pq.pop();
    return pq.top();
  }
};
