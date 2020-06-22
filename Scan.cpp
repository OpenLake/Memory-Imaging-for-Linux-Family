#include "ProcessManager.h"

#include <assert.h>

#include <vector>
#include <utility>

using namespace std;

/// Helper function for scanProcesses()
///
/// Takes a maps file and returns a vector of pairs 
/// having the beginning and ending addresses of readable
/// memory locations.
///
/// @param fileBuffer the maps file for a process
/// @returns a vector pairs
vector<pair<long, long>> getRanges(char *fileBuffer){
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
	return ranges;
}

/// Scanning Utility from address in Maps file
///
/// Takes in a target int value and matches it against all
/// readable memory locations' data.
///
/// @param target the int value to match
/// @returns vector of addresses
vector<long> ProcessManager::scanProcess(int target){
    int fd = 0;
	char fileLocation[1024];
	char* p = NULL;
	sprintf(fileLocation,"/proc/%lu/maps",pID);
	assert((fd=open(fileLocation,O_RDONLY)) >= 0);
	char *fileBuffer = new char[100000];
	assert(fileBuffer != NULL);
    memset(fileBuffer, 0, 100000);
	for (int i = 0; read(fd, fileBuffer + i, 1) > 0; i++);
	vector<pair<long, long>> ranges = getRanges(fileBuffer);
	vector<long> addresses;
	for(long i = 0; i<ranges.size(); i++){
		// cout << ranges.at(i).first<<"-"<<ranges.at(i).second<<endl;
		for(long j = ranges.at(i).first; j <= ranges.at(i).second - 4; j++){
			this->BaseAddress = j;
			getContent("int");
			// cout << contentInt << endl;
			if(this->contentInt == target){
				addresses.push_back(j);
			}
		}
	}
	cout << addresses.size() << " addresses matched" << endl;
	return addresses;
}

/// Scanning Utility from address in Maps file
///
/// Takes in a target long int value and matches it against all
/// readable memory locations' data.
///
/// @param target the long int value to match
/// @returns vector of addresses
vector<long> ProcessManager::scanProcess(long target){
    int fd = 0;
	char fileLocation[1024];
	char* p = NULL;
	sprintf(fileLocation,"/proc/%lu/maps",pID);
	assert((fd=open(fileLocation,O_RDONLY)) >= 0);
	char *fileBuffer = new char[100000];
	assert(fileBuffer != NULL);
    memset(fileBuffer, 0, 100000);
	for (int i = 0; read(fd, fileBuffer + i, 1) > 0; i++);
	vector<pair<long, long>> ranges = getRanges(fileBuffer);
	vector<long> addresses;
	for(long i = 0; i<ranges.size(); i++){
		// cout << ranges.at(i).first<<"-"<<ranges.at(i).second<<endl;
		for(long j = ranges.at(i).first; j <= ranges.at(i).second - 8; j++){
			this->BaseAddress = j;
			getContent("long");
			// cout << contentInt << endl;
			if(this->contentLongInt == target){
				addresses.push_back(j);
			}
		}
	}
	cout << addresses.size() << " addresses matched" << endl;
	return addresses;
}

/// Scanning Utility from address in Maps file
///
/// Takes in a target string value and matches it against all
/// readable memory locations' data.
///
/// @param target the string value to match
/// @returns vector of addresses
vector<long> ProcessManager::scanProcess(string target){
    int fd = 0;
	char fileLocation[1024];
	char* p = NULL;
	sprintf(fileLocation,"/proc/%lu/maps",pID);
	assert((fd=open(fileLocation,O_RDONLY)) >= 0);
	char *fileBuffer = new char[100000];
	assert(fileBuffer != NULL);
    memset(fileBuffer, 0, 100000);
	for (int i = 0; read(fd, fileBuffer + i, 1) > 0; i++);
	vector<pair<long, long>> ranges = getRanges(fileBuffer);
	vector<long> addresses;
	for(long i = 0; i<ranges.size(); i++){
		// cout << ranges.at(i).first<<"-"<<ranges.at(i).second<<endl;
		for(long j = ranges.at(i).first; j <= ranges.at(i).second - sizeof(target); j++){
			this->BaseAddress = j;
			getContent("string");
			// cout << contentInt << endl;
			if(this->contentString == target){
				addresses.push_back(j);
			}
		}
	}
	cout << addresses.size() << " addresses matched" << endl;
	return addresses;
}

/// Scanning Utility from address in Maps file
///
/// Takes in a target char value and matches it against all
/// readable memory locations' data.
///
/// @param target the char value to match
/// @returns vector of addresses
vector<long> ProcessManager::scanProcess(char target){
    int fd = 0;
	char fileLocation[1024];
	char* p = NULL;
	sprintf(fileLocation,"/proc/%lu/maps",pID);
	assert((fd=open(fileLocation,O_RDONLY)) >= 0);
	char *fileBuffer = new char[100000];
	assert(fileBuffer != NULL);
    memset(fileBuffer, 0, 100000);
	for (int i = 0; read(fd, fileBuffer + i, 1) > 0; i++);
	vector<pair<long, long>> ranges = getRanges(fileBuffer);
	vector<long> addresses;
	for(long i = 0; i<ranges.size(); i++){
		// cout << ranges.at(i).first<<"-"<<ranges.at(i).second<<endl;
		for(long j = ranges.at(i).first; j < ranges.at(i).second; j++){
			this->BaseAddress = j;
			getContent("char");
			// cout << contentInt << endl;
			if(this->contentChar == target){
				addresses.push_back(j);
			}
		}
	}
	cout << addresses.size() << " addresses matched" << endl;
	return addresses;
}

int main(){
	long id,BA;
	cout << "Enter PID of the Process\n";
	cin >> id;
	ProcessManager P(id,0,4);
	P.scanProcess(0);
	return 0;
}
