/*
    https://leetcode.com/problems/lru-cache/

    Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

    get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

    The cache is initialized with a positive capacity.

    Follow up:
    Could you do both operations in O(1) time complexity?

    Example:

    LRUCache cache = new LRUCache( 2 ); // capacity

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4

*/
class LRUCache {

    private int capacity;
    private Map<Integer,Integer> cache;
    private Map<Integer,Integer> freshness;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        cache = new HashMap<>();
        freshness = new LinkedList<>();
        freshnessMap = new HashMap<>();
    }

    public int get(int key) {
        if (cache.containsKey(key)) {
            freshness.remove(key);
            freshness.add(key);
            //System.out.print("get <"+key+"> = "); outputFreshness();
            return cache.get(key);
        } else {
            return -1;
        }
    }

    public void put(int key, int value) {

        if (freshness.contains(key)) {
            freshness.remove(key);
        }
        else if (freshness.size() >= capacity) {
            int oldKey = freshness.remove();
            cache.remove(oldKey);
        }
        freshness.add(key);
        cache.put(key,value);
        //System.out.print("put <"+key+"> = "); outputFreshness();
    }

    private void outputFreshness() {
        System.out.print("[");
        for (Integer i : freshness) {
            System.out.print(i + ",");
        }
        System.out.println("]");
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */