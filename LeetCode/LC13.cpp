/* LeetCode 13 - Roman to Integer */
/* by jennygaz */
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
  // grab the keys
  unordered_map<char, int> roman{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
  int ans {};
  // iterate from right to left
  for( int i = (int)s.length() - 1; i >= 0; -- i ){
    ans += roman[s[i]];
    if( i > 0 and roman[s[i]] > roman[s[i - 1]] ){ // we need to substract
      if( s[i - 1] == 'I' ) ans -= roman['I'];
      else if( s[i - 1] == 'X' ) ans -= roman['X'];
      else if( s[i - 1] == 'C' ) ans -= roman['C'];
      // but also to advance the pointer
      -- i;
    }
  }
  return ans;
}
