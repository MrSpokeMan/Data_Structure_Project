#include "HashMap.h"

template <typename Key, typename Value>
std::size_t HashMap<Key, Value>::hash(const Key& key) const 
{
	std::hash<Key> hasher;
	return hasher(key) % numBuckets;
}

template <typename Key, typename Value>
HashMap<Key, Value>::HashMap(std::size_t size) : numBuckets(size), buckets(size) {}


//Insert
template <typename Key, typename Value>
void HashMap<Key, Value>::insert(const Key& key, const Value& value)
{
    std::size_t bucketIndex = hash(key);
    BucketList& bucket = buckets[bucketIndex];

    for (auto& kvp : bucket)
    {
        if (kvp.first == key)
        {
            kvp.second = value;
            return;
        }
    }
    bucket.emplace_back(key, value);
}


template <typename Key, typename Value>
Value HashMap<Key, Value>::get(const Key& key) const {
    std::size_t bucketIndex = hash(key);
    const BucketList& bucket = buckets[bucketIndex];

    for (const auto& kvp : bucket) {
        if (kvp.first == key) {
            return kvp.second;
        }
    }

    return Value();
}


template <typename Key, typename Value>
bool HashMap<Key, Value>::remove(const Key& key) {
    std::size_t bucketIndex = hash(key);
    BucketList& bucket = buckets[bucketIndex];

    for (auto it = bucket.begin(); it != bucket.end(); it++) {
        if (it->first == key) {
            bucket.erase(it);
            return true;
        }
    }
    return false;
}