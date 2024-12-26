/* LeetCode 706 - Design HashMap */
/* by jennygaz */
struct KeyNode {
  int key;
  int val;
  KeyNode *next;
  KeyNode(int k, int v, KeyNode *next) : key(k), val(v), next(next) {}
};

class MyHashMap {
private:
  const static int _size = 10007;
  const static int _multiplier = 12582917;
  KeyNode *data[_size] = {};

  int _hash(int key) { return (int)((long long) key * (long long)_multiplier % (long long)_size); }

public:
  void put(int key, int value) {
    remove(key);
    const int hash = _hash(key);
    KeyNode *node = new KeyNode(key, value, data[hash]);
    data[hash] = node;
  }

  int get(int key) {
    const int hash = _hash(key);
    KeyNode *node = data[hash];
    while( node ) {
      if( node->key == key ) return node->val;
      node = node->next;
    }
    return -1;
  }

  void remove(int key) {
    const int hash = _hash(key);
    KeyNode *node = data[hash];
    if( not node ) return;
    if( node->key == key ) {
      data[hash] = node->next;
      delete node;
    } else {
      while( node->next ) {
	if( node->next->key == key ) {
	  KeyNode *tmp_node = node->next;
	  node->next = tmp_node->next;
	  delete tmp_node;
	  return;
	}
	node = node->next;
      }
    }
  }
};
