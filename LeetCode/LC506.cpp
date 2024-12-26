/* LeetCode 506 - Relative Ranks */
/* by jennygaz */
inline string make_prize(int rank) {
  switch (rank) {
  case 0: return "Gold Medal";
  case 1: return "Silver Medal";
  case 2: return "Bronze Medal";
  default: return to_string(rank + 1);
  }
}

vector<string> findRelativeRanks(vector<int>& score) {
  int current_idx {};
  vector<tuple<int, int>> sorted_ranks(score.size());
  std::transform(score.begin(), score.end(), sorted_ranks.begin(), [&](const int rank) -> std::tuple<int, int> {
      return {rank, current_idx ++ };
    });
  sort(sorted_ranks.begin(), sorted_ranks.end(), [](const auto& lhs, const auto& rhs) -> bool {
    return get<0>(lhs) != get<0>(rhs) ? get<0>(lhs) > get<0>(rhs) : get<1>(lhs) < get<1>(rhs);
  });
  vector<string> results(score.size(), "");
  for( int rank {}; rank < results.size(); ++ rank ) {
    int index = get<1>(sorted_ranks[rank]);
    results[index] = make_prize(rank);
  }
  return results;
}
