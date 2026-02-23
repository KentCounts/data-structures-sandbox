#include "hashtable.h"

std::size_t HashTable::hash(int key) const
{

    return static_cast<std::size_t>(
        (key % static_cast<int>(capacity) + static_cast<int>(capacity))
        % static_cast<int>(capacity)
        );
}