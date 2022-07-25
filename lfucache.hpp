//
// Created by ankolesn on 25.07.22.
//

#ifndef LAB18_4_LFUCACHE_HPP
#define LAB18_4_LFUCACHE_HPP
#include <string>
#include <unordered_map>
#include <vector>
#include <map>
#include <iterator>

using Rule_t = std::multimap<int, double>;
using Hash_t = std::unordered_map<int, Rule_t::iterator>;

template <typename T>
class LFU_Cache {
    size_t m_size;
    Hash_t hash;
    Rule_t rule;

public:
    explicit LFU_Cache(int size) : m_size(size) {}

    bool find_and_add(const T &address) {
        auto hit = hash.find(address);
        if ( hit == hash.end() ) {
            if (rule.size() == m_size) {
                auto del = rule.begin();
                hash.erase(del->second);
                rule.erase(del);
            }
            auto It = rule.insert(std::pair<int, T>(1, address));
            hash[address] = It;
            return false;
        }
        auto It = hit->second;
        int new_count = It->first + 1;
        rule.erase(hit->second);
        It = rule.insert(std::pair<int, T>(new_count, address));
        hash[address] = It;
        return true;
    }

    bool put(const T &address) {
        if (rule.size() == m_size) {
            auto del = rule.begin();
            hash.erase(del->second);
            rule.erase(del);
        }
        auto It =  rule.insert(std::make_pair(1, address));
        hash[address] = It;
        return false;
    }

    friend std::ostream& operator << (std::ostream& out, const LFU_Cache<T>& lfu){
        for (auto &i: lfu.rule) {
            out << "Value: " << i.second << std::endl;
        }
        return out;
    }
};

#endif //LAB18_4_LFUCACHE_HPP
