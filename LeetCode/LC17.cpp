/* LeetCode 17 - Letter Combinations of a Phone Number */
/* by jennygaz */
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

unordered_map<char, vector<char>> values {
  {'2', {'a', 'b', 'c'}},
  {'3', {'d', 'e', 'f'}},
  {'4', {'g', 'h', 'i'}},
  {'5', {'j', 'k', 'l'}},
  {'6', {'m', 'n', 'o'}},
  {'7', {'p', 'q', 'r', 's'}},
  {'8', {'t', 'u', 'v'}},
  {'9', {'w', 'x', 'y', 'z'}}
};

void dfs(int idx, string &state, string digits) {
  if( idx == (int)digits.length() ) {
    combinations.emplace_back(state);
    return;
  }
  for( const auto& item : values[digits[idx]] ) {
    state.push_back(item);
    dfs(idx + 1, state, digits);
    state.pop_back();
  }
}

vector<string> letterCombinations(string digits) {
  string tmp;
  stack<char> recursion;
  vector<string> combinations {};
  if( digits.length() == 0 ) return combinations;

  int current_idx {};
  for( const auto& c : values[digits[0]] ) {
    recursion.push(c);
    for( int idx {1}; idx < digits.size(); ++ idx ) {

    }
    recursion.pop();
  }
  return combinations;
}
