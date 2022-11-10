/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

// Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K,V> {

public:
    ChainingHash(int n = 11) {
        this->num_buckets = n;
        this->table = vector<vector<pair<K,V>>>(n);
    }

    ~ChainingHash() {
        this->clear();
    }

    int size() {
        return this->num_items;
    }

    V operator[](const K& key) {
        int bucket_idx = hash(key);
        const vector<pair<K, V>> bucket = table[bucket_idx];
        for(int i = 0; i < bucket.size(); ++i) {
            if(bucket[i].first == key) {
                return bucket[i].second;
            }
        }
        return {};
    }
    bool insert(const std::pair<K, V>& pair) {
        K key = pair.first;
        int bucket_idx = hash(key);
        table[bucket_idx].push_back(pair);
        ++this->num_items;
        if(load_factor() >= 1) {

        }
        return true;
    }

    void erase(const K& key) {
        int bucket_idx = hash(key);
        vector<pair<K,V>> bucket = table[bucket_idx];
        for(int i = 0; i < bucket.size(); ++i) {
            if(bucket[i].first == key) {
                bucket.erase(bucket.begin() + i);
                return;
            }
        }
        // TODO: erase failed
    }

    void clear() {
        this->num_buckets = this->num_items = 0;
        table = vector<vector<pair<K,V>>>(0);
    }

    int bucket_count() {
        return num_buckets;
    }
    // why on earth is this public??
    float load_factor() {
        return num_buckets == 0 ? 0.0 : num_items / num_buckets;
    }
    void rehash() {
        vector<pair<K,V>> items(num_items);
        for(int i = 0; i < num_buckets; ++i) {
            for(int j = 0; j < table[i].size(); ++j) {
                items.push_back(table[i][j]);
            }
        }
        this->num_buckets = findNextPrime(this->num_buckets);
        this->table = vector<vector<pair<K,V>>>(num_buckets);
        for(int i = 0; i < this->num_buckets; ++i) {
            insert(items[i]);
        }

    
    }

private:

    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        return (key % num_buckets);
    }

    int num_buckets = 0;
    int num_items = 0;
    // using a vector as opposed to a list for the bucket because this removes the memory overhead from lists and a potential performance gain (no need to allocate space on the heap on insert)
    vector<vector<pair<K,V>>> table;
    

};

#endif //__CHAINING_HASH_H
