#include "ProcessManager.h"

#include <vector>
#include <utility>

using namespace std;

/// Scanning Utility from addresses in vector
///
/// Takes in a target int value and matches it against all
/// memory locations specified in the vector and returns a
/// new vector containing all matched addresses.
///
/// @param addresses the vector of addresses to check
/// @param target the value to match
/// @returns vector of addresses containing target value
vector<long> ProcessManager::scanProcess(vector <long> addresses, int target){
    vector<long> matches;
    for(long i=0; i<addresses.size(); i++){
        this->BaseAddress = addresses.at(i);
        this->getContent("int");
        if(this->contentInt == target){
            matches.push_back(addresses.at(i));
        }
    }
    if (debug ==true){
        cout << matches.size() << " addresses matches" << endl;
    }
    return matches;
}

/// Scanning Utility from addresses in vector
///
/// Takes in a target long int value and matches it against all
/// memory locations specified in the vector and returns a
/// new vector containing all matched addresses.
///
/// @param addresses the vector of addresses to check
/// @param target the value to match
/// @returns vector of addresses containing target value
vector<long> ProcessManager::scanProcess(vector <long> addresses, long target){
    vector<long> matches;
    for(long i=0; i<addresses.size(); i++){
        this->BaseAddress = addresses.at(i);
        this->getContent("long");
        if(this->contentLongInt == target){
            matches.push_back(addresses.at(i));
        }
    }
    if (debug ==true){
        cout << matches.size() << " addresses matches" << endl;
    }
    return matches;
}

/// Scanning Utility from addresses in vector
///
/// Takes in a target char value and matches it against all
/// memory locations specified in the vector and returns a
/// new vector containing all matched addresses.
///
/// @param addresses the vector of addresses to check
/// @param target the value to match
/// @returns vector of addresses containing target value
vector<long> ProcessManager::scanProcess(vector <long> addresses, char target){
    vector<long> matches;
    for(long i=0; i<addresses.size(); i++){
        this->BaseAddress = addresses.at(i);
        this->getContent("char");
        if(this->contentChar == target){
            matches.push_back(addresses.at(i));
        }
    }
    if (debug ==true){
        cout << matches.size() << " addresses matches" << endl;
    }
    return matches;
}

/// Scanning Utility from addresses in vector
///
/// Takes in a target string value and matches it against all
/// memory locations specified in the vector and returns a
/// new vector containing all matched addresses.
///
/// @param addresses the vector of addresses to check
/// @param target the value to match
/// @returns vector of addresses containing target value
vector<long> ProcessManager::scanProcess(vector <long> addresses, string target){
    vector<long> matches;
    for(long i=0; i<addresses.size(); i++){
        this->BaseAddress = addresses.at(i);
        this->getContent("string");
        if(this->contentString == target){
            matches.push_back(addresses.at(i));
        }
    }
    if (debug ==true){
        cout << matches.size() << " addresses matches" << endl;
    }
    return matches;
}
