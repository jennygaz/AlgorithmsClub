inline std::tuple<int, int>
divmod64(int num) {
  const int mask = 64 - 1;
  const int mod = num & mask;
  const int res = num & (~mask);
  const int section = res >> 6;
  return { section, mod };
}

inline int
removeDuplicates(vector<int>& nums) {
  const int offset = 10000;
  const int max_bitmask_count = 512;
  unsigned long long seen[512] {}, repeated[512] {};
  int min_seen = offset;
  int max_seen = -offset;
  for( auto& num: nums ) {
    const int index = num + offset;
    min_seen = min(index, min_seen);
    max_seen = max(index, max_seen);
    const auto& [section, sub_index] = divmod64(index);
    const unsigned long long shift = (1ULL << sub_index);
    const unsigned long long seen_bit = seen[section] & shift;
    if( seen_bit ) repeated[section] |= shift;
    seen[section] |= shift;
  }
  int current_index {};
  for( int num = min_seen; num <= max_seen; ++ num ) {
    const auto& [section, sub_index] = divmod64(num);
    const unsigned long long shift = (1ULL << sub_index);
    const unsigned long long seen_bit = seen[section] & shift;
    const unsigned long long repeated_bit = repeated[section] & shift;
    if( seen_bit )
      nums[current_index ++] = num - offset;
    if( repeated_bit )
      nums[current_index ++] = num - offset;
  }
  return current_index;
}
