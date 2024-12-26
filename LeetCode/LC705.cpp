/* LeetCode 705 - Design HashSet */
/* by jennygaz */
class MyHashSet {
private:
  long _prime_base;
  std::vector<std::list<int>> _buckets;

  int hash(int key) { return key % _prime_base; }

  std::list<int>::iterator search(int key) {
    const int h = hash(key);
    return find(_buckets[h].begin(), _buckets[h].end(), key);
  }
public:
  MyHashSet() : _prime_base(1000007), _buckets(1000007) {}
    
  void add(int key) {
    const int mod_key = hash(key);
    if( not contains(key) ) _buckets[mod_key].emplace_back(key);
  }
    
  void remove(int key) {
    const int mod_key = hash(key);
    auto it = search(key);
    if( it != _buckets[mod_key].end() )
      _buckets[mod_key].erase(it);
  }
    
  bool contains(int key) {
    const int mod_key = hash(key);
    return search(key) != _buckets[mod_key].end();
  }
};
