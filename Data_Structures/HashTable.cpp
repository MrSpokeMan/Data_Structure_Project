#include "HashTable.h"

template <typename Key, typename Value>
std::size_t HashTable<Key, Value>::hash(const Key& key) const 
{
	std::hash<Key> hasher;
	return hasher(key) % numBuckets;
}

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(std::size_t size) : numBuckets(size), buckets(size) {}


//Insert
template <typename Key, typename Value>
void HashTable<Key, Value>::insert(const Key& key, const Value& value)
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
Value HashTable<Key, Value>::get(const Key& key) const {
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
bool HashTable<Key, Value>::remove(const Key& key) {
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