/* LeetCode 438 - Find All Anagrams in a String */
/* by jennygaz */
#include <vector>
#include <string>

using namespace std;

vector<int> findAnagrams(string s, string p) {
  vector<int> ans;
  int count[256] {};
  int required = p.length();
  for( const char c : p ) ++ count[c];
  for( int lhs {}, rhs {}; rhs < s.length(); ++ rhs ) {
    if( -- count[s[rhs]] >= 0 ) -- required;
    while( required == 0 ) {
      if( rhs - lhs + 1 == p.length() ) ans.emplace_back(lhs);
      if( ++ count[s[lhs ++]] > 0 ) ++ required;
    }
  }
  return ans;
}
