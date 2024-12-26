/* LeetCode 18 - 4Sum */
/* by jennygaz */
vector<vector<int>> fourSum(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> result;
  for( int i {}; i < (int)nums.size() - 3; ++ i ) {
    for( int j = i + 1; j < (int)nums.size() - 2; ++ j ) {
      long long current_target = (long long)target - (long long)nums[i] - (long long)nums[j];
      int lhs = j + 1, rhs = nums.size() - 1;
      while( lhs < rhs ) {
	if( nums[lhs] + nums[rhs] < current_target ) ++ lhs;
	else if( nums[lhs] + nums[rhs] > current_target ) -- rhs;
	else {
	  const vector<int> ans = {nums[i], nums[j], nums[lhs], nums[rhs]};
	  result.emplace_back(ans);
	  int next_lhs = lhs, next_rhs = rhs;
	  while( lhs < rhs and nums[lhs] == nums[next_lhs] ) ++ lhs;
	  while( lhs < rhs and nums[rhs] == nums[next_rhs] ) -- rhs;
	}
      }
      while( j + 1 < nums.size() and nums[j] == nums[j + 1] ) ++ j;
    }
    while( i + 1 < nums.size() and nums[i] == nums[i + 1] ) ++ i;
  }
  return result;
}
