#include <iostream>
#include "lfucache.hpp"

int main() {
    LFU_Cache<int> lfu(3);
    lfu.put(1);
    lfu.put(2);
    lfu.put(1);
    lfu.put(3);
    lfu.find_and_add(4);
    std::cout << lfu;
    return 0;
}
