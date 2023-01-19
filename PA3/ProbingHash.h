#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};


template<typename K, typename V>
class ProbingHash : public Hash<K,V> { // derived from Hash
private:
    vector<pair<pair<K,V>, EntryState>> table;
    int table_capacity = 0;
    int num_items = 0;

public:
    ProbingHash(int n = 11) {
        this->table_capacity = n;
        table = vector<pair<pair<K,V>, EntryState>>(this->table_capacity, {{-1, -1}, EMPTY});
    }

    ~ProbingHash() {
        this->clear();
    }

    int size() {
        return this->num_items;
    }

    V operator[](const K& key) {
        int bucket_idx = hash(key);
        while(bucket_idx < this->table_capacity && table[bucket_idx].second != EMPTY && table[bucket_idx].second != DELETED && table[bucket_idx].first.first != key) {
            ++bucket_idx;
        }
        if(bucket_idx > this->table_capacity || table[bucket_idx].second == EMPTY || table[bucket_idx].second == DELETED) {
            return {};
        }
        return table[bucket_idx].first.second;

    }

    bool insert(const std::pair<K, V>& pair) {
        K key = pair.first;
        int bucket_idx = hash(key);
        while(bucket_idx < this->table_capacity && (table[bucket_idx].second != EMPTY && table[bucket_idx].second != DELETED)) {
            ++bucket_idx;
        }
        if(bucket_idx >= this->table_capacity || table[bucket_idx].first.first == pair.first) {
            return false;
        }
        std::pair<std::pair<K,V>, EntryState> element = {pair, VALID};
        table[bucket_idx] = element;
        ++num_items;
        if(load_factor() >= LOAD_FACTOR) {
            rehash();
        }
        return true;
    }

    void erase(const K& key) {
        int bucket_idx = hash(key);
        while(bucket_idx < this->table_capacity && table[bucket_idx].second != EMPTY && table[bucket_idx].second != DELETED && table[bucket_idx].first.first != key) {
            ++bucket_idx;
        }
        if(bucket_idx > this->table_capacity || table[bucket_idx].second == EMPTY || table[bucket_idx].second == DELETED) {
            return;
        }
        table[bucket_idx].second = DELETED;
        --num_items;
    }

    void clear() {
        this->table_capacity = 0;
        this->table.clear();
    }

    int bucket_count() {
        return this->table_capacity;
    }

    float load_factor() {
        return this->table_capacity == 0 ? 0.0 : (float)this->num_items / this->table_capacity;
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
    void rehash() {
        vector<std::pair<K,V>> items;
        items.reserve(num_items);
        for(auto itr:table) {
            if(itr.second == VALID) {
                items.push_back(itr.first);
            }
        }
        
        if(items.size() != num_items) {
            // problem
            return;
        }
        this->table_capacity = findNextPrime(this->table_capacity << 1);
        this->table.clear();
        this->num_items = 0;
        this->table.resize(this->table_capacity, {{-1,-1}, EMPTY});
        for(auto itr:items) {
            insert(itr);
        }
        return;
    }

    int hash(const K& key) {
        return key % table_capacity;       
    }
    
};

#endif //__PROBING_HASH_H
