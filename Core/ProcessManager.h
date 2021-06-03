//https://www.gnu.org/software/libc/manual/html_node/Feature-Test-Macros.html
#define _DEFAULT_SOURCE
//https://gcc.gnu.org/onlinedocs/libstdc++/manual/using_macros.html
#define _GLIBCXX_USE_CXX11_ABI 0

#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<fcntl.h>
#include<dirent.h>
#include<errno.h>
#include<sys/uio.h>

#include <elf.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <cerrno>


#include<iomanip>
#include<sstream>
#include<cstdlib>
#include<utility>
#include<vector>
#include<unordered_map>

#include "Tools.h"

/*[TODO] :
1. Add return codes when exiting
*/

///Every readable information is scanned and stored in ProcessManager.s
///
///This makes ProcessManager the basic building block of the engine.
///ProcessManager stores #pID of the process whose memory has to be scanned. In addition the class stores the starting memory address where the relevant/possible datata is stored in #BaseAddress.
///#span stores the number of subsequent memory addresses after #BaseAddress (including #BaseAddress) are to be read in order to construct a meaningful data out of a given memory location. #span value is 4 for an int value, 8 for a long int or memory address value and variable (equal to string size) for string value (*for a 64 bit framework*).
///Furthermore, a larger span value can be used to access the contents of a desired number of memory location.
/// #contentInt/#contentLongHex/#contentChar/#contentString members store the data read from the memory addresses akin to how the data is stored in variables in a standard programming language. #contentInt stores the int interpretation of data, #contentLongHex stores long int/memory address  (*which in turn will make the BaseAddress as a pointer to this memory address*)  interpretation of the data and so on.
class ProcessManager
{
private:
	Elf64_Ehdr elf_header;

	uint32_t pID; // the max value is 2^22 on 64 bit systems

	//objects which need to be destroyed afterwards
	int mem_handle;

	int exe_handle;
	void *exe_map;
	struct stat exe_stats;

	std::string exe_path;
	std::vector<Elf64_auxv_t> aux_vector;
public:

	/// utility for storing pointers in the mapping
	// struct pointerNode{
	// 	long address;
	// 	struct pointerNode * next;
	// };



	///Class constructor for ProcessManager.
	///
	/// @param id : PID of the process in which we are interested.
	ProcessManager(uint32_t);

	~ProcessManager();

	//stuff to parse the executable
	void get_exe_path(uint32_t);
	void parse_headers();

	// void FindBaseAddress(char* Module = NULL);
	// void PrintContent();
	// char* Read();
	// void getContent(string Module);
	// void getAddresses();
	// bool isAddress(long testval);
	// unordered_map<long, ProcessManager::pointerNode*> getPointerMap(vector<long> addresses);
	// vector<long> scanProcess();
	// vector<long> scanProcess(int target);
	// vector<long> scanProcess(long target);
	// vector<long> scanProcess(string target);
	// vector<long> scanProcess(char target);
	// vector<long> scanProcess(vector<long> addresses, int target);
	// vector<long> scanProcess(vector<long> addresses, long target);
	// vector<long> scanProcess(vector<long> addresses, string target);
	// vector<long> scanProcess(vector<long> addresses, char target);
};
