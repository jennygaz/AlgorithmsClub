/* LeetCode 451 - Sort Characters by Frequency */
/* by jennygaz */
string frequencySort(string s) {
  unordered_map<int, int> frequencies {};
  for( auto c : s ) ++ frequencies[c];
  vector<tuple<int, int>> sorted_freqs {};
  sorted_freqs.reserve(frequencies.size());
  for( auto &[key, value] : frequencies ) 
    sorted_freqs.emplace_back(value, key);
  sort(sorted_freqs.begin(), sorted_freqs.end(), [](const auto &lhs, const auto &rhs) -> bool {
    return get<0>(lhs) != get<0>(rhs) ? get<0>(lhs) > get<0>(rhs) : get<1>(lhs) < get<1>(rhs);
  });
  string result {};
  for( auto &[frequency, key] : sorted_freqs ) {
    int freq = frequency;
    while( freq -- ) result += (char)(key);
  }
  return result;
}
