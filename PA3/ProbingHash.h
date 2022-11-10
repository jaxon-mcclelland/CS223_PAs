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
    int size = 0;
    int items = 0;

public:
    ProbingHash(int n = 11) {
        this->size = n;
        table = vector<pair<pair<K,V>, EntryState>>(this->size);
    }

    ~ProbingHash() {
        this->clear();
    }

    int size() {
        return this->size;
    }

    V operator[](const K& key) {
        int bucket_idx = hash(key);
        while(table[bucket_idx].second != EMPTY) {
            if(table[bucket_idx].first.first == key) {
                return table[bucket_idx].first.second;
            }
        }
        return {};
    }

    bool insert(const std::pair<K, V>& pair) {
        K key = pair.first;
        int bucket_idx = hash(key);
        while(bucket_idx < this->size && table[bucket_idx].second != EMPTY) {
            if(table[bucket_idx].first.first == pair.first) {
                return false;
            }
        }
        if(bucket_idx >= this->size) {
            return false;
        }
        std::pair<K,V> input_pair = pair;
        table[bucket_idx] = std::make_pair<std::pair<K,V>, EntryState>(input_pair, VALID);
        return true;


    }

    void erase(const K& key) {
        int bucket_idx = hash(key);
        while(bucket_idx < this->size && table[bucket_idx].second != EMPTY) {
            if(table[bucket_idx].first.first == key) {
                table[bucket_idx] = std::make_pair<pair<K,V>, EntryState>(table[bucket_idx].first, DELETED);
                return;
            }
            ++bucket_idx;
        }
    }

    void clear() {
        this->size = 0;
        this->table = vector<pair<pair<K,V>, EntryState>>(0);
    }

    int bucket_count() {
        return this->items;
    }

    float load_factor() {
        return this->size == 0 ? 0 : this->items / this->size;
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
        return key % size;       
    }
    
};

#endif //__PROBING_HASH_H
