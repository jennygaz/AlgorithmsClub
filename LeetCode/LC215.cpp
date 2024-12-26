/* LeetCode 215 - Kth Largest Element in an Array */
/* by jennygaz */
int findKthLargest(vector<int>& nums, int k) {
  std::nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>());

  return nums[k - 1];
  /* Regular way is use a heap or sort partially */
  /*
    std::priority_queue<int> pq(nums.begin(), nums.end());
    while( -- k >= 0 ) pq.pop();
    return pq.top();
  */
  /* Using partial sort */
  /*
    std::partial_sort(nums.begin(), nums.begin() + k, nums.end());
    return nums[k - 1];
   */
}
