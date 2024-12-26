/* LeetCode 1834 - Single Threaded CPU */
/* by jennygaz */
vector<int> getOrder(vector<vector<int>>& tasks) {
  std::priority_queue<
    std::tuple<int, int>,
    std::vector<std::tuple<int, int>>,
    std::greater<std::tuple<int, int>>
    > pq {};
  long time {}, idx {};
  for( int i = 0; i < (int)(tasks.size()); ++ i )
    tasks[i].emplace_back(i);
  std::sort(tasks.begin(), tasks.end());
  std::vector<int> result {};
  while( idx < (int)(tasks.size()) or pq.size() ) {
    if( pq.empty() ) time = max(time, (long)tasks[idx][0]);
    while( idx < (long)(tasks.size()) and time >= tasks[idx][0] ) {
      pq.emplace(tasks[idx][1], tasks[idx][2]);
      ++ idx;
    }
    auto &[processing_time, index] = pq.top();
    pq.pop();
    time += processing_time;
    result.emplace_back(index);
  }
  return result;
}
