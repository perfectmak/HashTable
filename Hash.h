/* 
 * File:   Hash.h
 * Author: perfectmak
 *
 * Created on September 26, 2015, 2:07 AM
 */

#ifndef HASH_H
#define	HASH_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

template<typename K, typename V>
class Hash {
private:    
    struct _Pair
    {
        _Pair() : isDefault(true){}
        _Pair(K& key, V& value) : key(key), value(value), isDefault(false){}
        K key;
        V value;
        bool isDefault;
    };
public:
    Hash() : _DEFAULT_MAP_SIZE(20) {
        _size = 0;
        _buckets = std::vector<_Pair*>(_DEFAULT_MAP_SIZE, new _Pair());
    }
    
    void insert(K key, V value) {
        
        int hash = _hashValue(key);
        if(_buckets[hash]->isDefault)
        {
//            _buckets.insert(_buckets.begin(), new _Pair(key,value));
            _buckets[hash] = new _Pair(key,value);
        }
        else
        {
            //look for a position to put it
            //using linear probing
            int initialHash = hash;
            while(!_buckets[hash]->isDefault)
            {
                hash = (hash+1)%_buckets.size();
                
                if((initialHash == hash))
                    break;
            }
            
            if(initialHash == hash) //no more space
            {                
                //extend the vector and update hash value;                
                _buckets.resize(_buckets.size()+_DEFAULT_MAP_SIZE);
                hash = _buckets.size();
            }
            
            _buckets[hash] = new _Pair(key, value);
        }
        
        _size++;
    }

    /**
     * Returns the value associated with the
     * @param key
     * @return 
     */
    V& get(K key)
    {
        int hash = _hashValue(key);
        //search for value
        int initialHash = hash;
        while((!_buckets[hash]->isDefault))
        {
            if(_buckets[hash]->key == key)
            {
                return _buckets[hash]->value;
            }
            hash = (hash+1)%_buckets.size();
            
            if(initialHash == hash)
                break;
        }
        //not found
        std::ostringstream os;
        os << "Key '" << key << "' not found.";
        throw (std::string(os.str()));
    }
    
    unsigned int size() {
        return _size;
    }

private:
    /**
     * has value is computed based on address of key variable
     * @param key
     * @return 
     */
    int _hashValue(K key, int modulo = 20) {
        return 3%modulo;
    }
    
    const int _DEFAULT_MAP_SIZE;
    
    std::vector<_Pair*> _buckets;
    unsigned int _size;
};

#endif	/* HASH_H */

