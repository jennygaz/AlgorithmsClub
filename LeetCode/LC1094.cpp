/* LeetCode 1094 - Car Pooling */
/* by jennygaz */
bool carPooling(vector<vector<int>>& trips, int capacity) {
  std::map<int, int> people {};
  for( auto& trip : trips ) {
    people[trip[1]] += trip[0];
    people[trip[2]] -= trip[0];
  }
  for( auto &[_, value] : people )
    if( (capacity -= value) < 0 ) return false;
  return true;
}
