/* LeetCode 454 - 4Sum II */
/* by jennygaz */
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
  int count {};
  unordered_map<int, int> frequencies {};
  for( const auto& lhs : nums1 )
    for( const auto& rhs : nums2 )
      ++ frequencies[lhs + rhs];
  for( const auto& lhs : nums3 )
    for( const auto& rhs : nums4 )
      count += frequencies[-(lhs + rhs)];
  return count;
}
