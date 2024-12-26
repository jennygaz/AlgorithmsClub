/* LeetCode 1206 - Design SkipList */
/* by jennygaz */
class Skiplist {
private:
  const int _k_max_height = 8;

  struct Node {
    int val;
    int height;
    Node **next;

    Node(int v, int h) : val(v), height(h) {
      next = new Node*[h];
      while( -- h >= 0 ) next[h] = nullptr;
    }

    ~Node() { delete[] next; }
  };

  int _get_random_height() {
    int h = 1;
    while( h < _k_max_height and rand() % 4 == 1 ) ++ h;
    return h;
  }

  Node* _find_greater_or_equal(int target, Node **prev ) {
    Node *it = head;
    int level = _k_max_height - 1;
    while( true ) {
      Node *next = it->next[level];
      if( next and next->val < target ) it = next;
      else {
	if( prev ) prev[level] = it;
	if( level == 0 ) return next;
	else -- level;
      }
    }
  }

  Node *head;
public:
  Skiplist() {
    head = new Node(0, _k_max_height);
  }
    
  bool search(int target) {
    Node *node = _find_greater_or_equal(target, nullptr);
    return node != nullptr and node->val == target;
  }
    
  void add(int num) {
    Node *prev[_k_max_height];
    _find_greater_or_equal(num, prev);

    Node *node = new Node(num, _get_random_height());
    for( int i = 0; i < node->height; ++ i ) {
      node->next[i] = prev[i]->next[i];
      prev[i]->next[i] = node;
    }
  }
    
  bool erase(int num) {
    Node* prev[_k_max_height];
    Node *to_del = _find_greater_or_equal(num, prev);
    if( to_del == nullptr or to_del->val != num ) return false;
    for( int i = 0; i < to_del->height; ++ i ) prev[i]->next[i] = to_del->next[i];
    delete to_del;
    return true;
  }
};
