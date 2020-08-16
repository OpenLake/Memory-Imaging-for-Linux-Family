#include "ProcessManager.h"

set <unsigned long> ProcessManager::MemoryOffsets(vector <long> addresses)
{
    FindBaseAddress("r-xp");
    set <unsigned long> offset;
    offset.insert(0);
    for(unsigned long i=0;i<addresses.size();i++)
    {
        unsigned long val = addresses[i]-BaseAddress;
        offset.insert(val);
    }
    return offset;
}

set <unsigned long> ProcessManager::StaticMemorySet(set<unsigned long> offsets1,set<unsigned long> offsets2)
{
    vector <unsigned long> v1;
    vector<unsigned long>::iterator vl= set_intersection(offsets1.begin(),offsets1.end(),offsets2.begin(),offsets2.end(),v1.begin());
    set <unsigned long> StaticMem (v1.begin(),vl);
    return StaticMem;
}