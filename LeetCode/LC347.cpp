/* LeetCode 347 - Top K Frequent Elements */
/* by jennygaz */
#include <vector>
#include <unordered_map>
#include <tuple>
#include <functional>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
  unordered_map<int, int> frequencies {};
  for( const auto& num : nums )
    ++ frequencies[num];
  vector<tuple<int, int>> sorted_pairs;
  sorted_pairs.reserve( frequencies.size() );
  for( auto& [num, freq] : frequencies )
    sorted_pairs.emplace_back( freq, num );
  sort( sorted_pairs.begin(), sorted_pairs.end(), 
	[]( const auto& lhs, const auto& rhs ) -> bool {
	  return get<0>( lhs ) < get<0>( rhs );
        });
  vector<int> result;
  result.reserve(k);
  for( int i = (int)(sorted_pairs.size() - 1); k -- and i >= 0; -- i )
    result.emplace_back( get<1>( sorted_pairs[i] ) );
  return std::move(result);
}
