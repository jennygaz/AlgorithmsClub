/* LeetCode 421 - Maximum XOR of Two Numbers in an Array */
/* by jennygaz */
struct TrieNode {
  TrieNode *children[2];

  TrieNode(TrieNode *lhs_ = nullptr, TrieNode *rhs_ = nullptr) {
    this->children[0] = lhs_;
    this->children[1] = rhs_;
  }
};

class Solution {
private:
  TrieNode *head;

  void insert(int value) {
    TrieNode *node = head;
    bitset<32> bin(value);
    for( int bit_idx = 31; bit_idx >= 0; -- bit_idx ) {
      if( not node->children[bin[bit_idx]] )
	node->children[bin[bit_idx]] = new TrieNode();
      node = node->children[bin[bit_idx]];
    }
  }
public:
  Solution() {
    head = new TrieNode();
  }
  int compute_max_xor(int num) {
    TrieNode *node = head;
    bitset<32> bin(num);
    int ans {};
    for( int bit_idx = 31; bit_idx >= 0; -- bit_idx ) {
      if( node -> children[!bin[bit_idx]] )
	ans += (1 << bit_idx), node = node->children[!bin[bit_idx]];
      else
	node = node->children[bin[bit_idx]];
    }
    return ans;
  }

  int findMaximumXOR(vector<int>& nums) {
    for( const auto& num : nums ) insert(num);
    int ans {};
    for( const auto& num : nums ) ans = max(ans, compute_max_xor(num));
    return ans;
  }
};
