#include "ProcessManager.h"

using namespace std;

/// Pointer Mapping Utility
///
/// Takes in a vector of addresses and returns an unordered
/// map with key as addresses which point to other addresses
/// and values as a struct which stores information about their
/// contents and mappings.
///
/// @param addresses vector of addresses
/// @returns an unordered map with mappings
unordered_map<long, ProcessManager::pointerNode*> ProcessManager::getPointerMap(vector<long> addresses){
    unordered_map<long, ProcessManager::pointerNode*> mappings;
    for(auto x : addresses){
        this->BaseAddress = x;
        this->getContent("address");
        if(this->isAddress(this->contentLongInt)){
            struct pointerNode *node = (struct pointerNode*)malloc(sizeof(struct pointerNode));
            node->address = this->contentLongInt;
            node->next = NULL;
            mappings[x] = node;
        }
    }
    for(auto x : mappings){
        if(mappings.find(x.second->address) != mappings.end()){
            x.second = mappings[x.second->address];
        }
    }
    return mappings;
}
