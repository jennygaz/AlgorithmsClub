/* LeetCode 1464 - Maximum Product of Two Elements in an Array */
/* by jennygaz */
int maxProduct(vector<int>& nums) {
  int max_value {0}, second_max {0}, max_index {-1}, second_max_index {-1};
  for( int i = 0; i < (int)nums.size(); ++ i ) {
    if( nums[i] > max_value ) {
      if( max_value > second_max ) {
	second_max = max_value;
	second_max_index = max_index;
      }
      max_value = nums[i];
      max_index = i;
                
    } else if( nums[i] > second_max and i != max_index ) {
      second_max = nums[i];
      second_max_index = i;
    }
  }
  return (max_value - 1) * (second_max - 1);
}
