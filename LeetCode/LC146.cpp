/* LeetCode 146 - LRU Cache */
/* by jennygaz */
struct Node {
    int key;
    int value;
};

class LRUCache {
private:
    const int capacity;
    list<Node> cache;
    unordered_map<int, list<Node>::iterator> iterator_for;
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        const auto it = iterator_for.find(key);
        if( it == iterator_for.cend() ) return -1;
        const auto& list_it = it->second;
        cache.splice(cache.begin(), cache, list_it);
        return list_it->value;
    }

    void put(int key, int value) {
        if( const auto it = iterator_for.find(key); 
            it != iterator_for.cend() ) {
            const auto& list_it = it->second;
            cache.splice(cache.begin(), cache, list_it);
            list_it->value = value;
            return;
        }
        if( cache.size() == capacity ) {
            const Node& last_node = cache.back();
            iterator_for.erase(last_node.key);
            cache.pop_back();
        }
        cache.emplace_front(key, value);
        iterator_for[key] = cache.begin();
    }
};
