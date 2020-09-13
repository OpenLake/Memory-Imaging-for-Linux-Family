#include "ProcessManager.h"

#include <assert.h>

using namespace std;

/// Scanning Utility from addresses in Maps file
///
/// Returns a vector of readable addresses for a
/// process from its maps file.
///
/// @returns vector of addresses
vector<long> ProcessManager::scanProcess(){
	int fd = 0;
	char fileLocation[1024];
	sprintf(fileLocation,"/proc/%lu/maps",this->pID);
	assert((fd=open(fileLocation,O_RDONLY)) >= 0);
	char *fileBuffer = new char[100000];
	assert(fileBuffer != NULL);
    memset(fileBuffer, 0, 100000);
	for (int i = 0; read(fd, fileBuffer + i, 1) > 0; i++);
	vector<pair<long, long>> ranges;
	char *p;
	char *m = fileBuffer;
	while((p=strstr(m, "\n"))!=NULL){
		char *start = p-1;
		while( (*start) != '\n' && start>=fileBuffer)
		{
			start--;
		}
		start++;
		char *c=strstr(start, "---p");
		if(c&&c<strstr(start,"\n")){
			m=p+1;
			continue;
		}
		char chAddress[1024];
		assert(chAddress != NULL);
		memset(chAddress, 0, 1024);
		for(int i=0;*start!='-';i++)
		{
			chAddress[i] = *start;
			start++;
		}
		pair<long, long> range;
		range.first = strtol(chAddress, NULL, 16);
		memset(chAddress, 0, 1024);
		start++;
		for (int i = 0; *start != ' '; i++)
		{
			chAddress[i] = *start;
			start++;
		}
		range.second = strtol(chAddress, NULL, 16);
		ranges.push_back(range);
		m = p + 1;
	}
	vector<long> addresses;
	for(long i = 0; i<ranges.size(); i++){
		if (debug ==true){
		cout << "Ranges"<< ranges.at(i).first<<"-"<<ranges.at(i).second<<endl;
		}
		for(long j = ranges.at(i).first; j < ranges.at(i).second; j++){
			addresses.push_back(j);
		}
	}
	if (debug ==true){
		cout << addresses.size() << " addresses found";
	}
	return addresses;
}

/// Scanning Utility from addresses in Maps file
///
/// Takes in a target int value and matches it against all
/// readable memory locations' data.
///
/// @param target the int value to match
/// @returns vector of addresses
vector<long> ProcessManager::scanProcess(int target){
	vector<long> matches;
	vector<long> addresses = this->scanProcess();
	for(long i = 0; i < addresses.size(); i++){
		this->BaseAddress = addresses.at(i);
		this->getContent("int");
		if(this->contentInt == target){
			matches.push_back(addresses.at(i));
		}
	}
	if (debug ==true){
		cout << matches.size() << " addresses matched" << endl;
	}
	return matches;
}

/// Scanning Utility from address in Maps file
///
/// Takes in a target long int value and matches it against all
/// readable memory locations' data.
///
/// @param target the long int value to match
/// @returns vector of addresses
vector<long> ProcessManager::scanProcess(long target){
    vector<long> matches;
	vector<long> addresses = this->scanProcess();
	for(long i = 0; i < addresses.size(); i++){
		this->BaseAddress = addresses.at(i);
		this->getContent("long int");
		if(this->contentLongInt == target){
			matches.push_back(addresses.at(i));
		}
	}
	if (debug ==true){
		cout << matches.size() << " addresses matched" << endl;
	}
	return matches;
}

/// Scanning Utility from address in Maps file
///
/// Takes in a target string value and matches it against all
/// readable memory locations' data.
///
/// @param target the string value to match
/// @returns vector of addresses
vector<long> ProcessManager::scanProcess(string target){
    vector<long> matches;
	vector<long> addresses = this->scanProcess();
	for(long i = 0; i < addresses.size(); i++){
		this->BaseAddress = addresses.at(i);
		this->getContent("string");
		if(this->contentString == target){
			matches.push_back(addresses.at(i));
		}
	}
	if (debug ==true){
		cout << matches.size() << " addresses matched" << endl;
	}
	return matches;
}

/// Scanning Utility from address in Maps file
///
/// Takes in a target char value and matches it against all
/// readable memory locations' data.
///
/// @param target the char value to match
/// @returns vector of addresses
vector<long> ProcessManager::scanProcess(char target){
    vector<long> matches;
	vector<long> addresses = this->scanProcess();
	for(long i = 0; i < addresses.size(); i++){
		this->BaseAddress = addresses.at(i);
		this->getContent("char");
		if(this->contentChar == target){
			matches.push_back(addresses.at(i));
		}
	}
	if (debug ==true){
		cout << matches.size() << " addresses matched" << endl;
	}
	return matches;
}

