#define _DEFAULT_SOURCE
#define _GLIBCXX_USE_CXX11_ABI 0

#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<dirent.h>
#include<errno.h>
#include<sys/uio.h>

#include<iomanip>
#include<sstream>
#include<cstdlib>
#include<vector>


using namespace std;
typedef unsigned int uint;
///Every readable information is scanned and stored in ProcessManager.  
///
///This makes ProcessManager the basic building block of the engine.
///ProcessManager stores #pID of the process whose memory has to be scanned. In addition the class stores the starting memory address where the relevant/possible datata is stored in #BaseAddress.
///#span stores the number of subsequent memory addresses after #BaseAddress (including #BaseAddress) are to be read in order to construct a meaningful data out of a given memory location. #span value is 4 for an int value, 8 for a long int or memory address value and variable (equal to string size) for string value (*for a 64 bit framework*).
///Furthermore, a larger span value can be used to access the contents of a desired number of memory location.
/// #contentInt/#contentLongHex/#contentChar/#contentString members store the data read from the memory addresses akin to how the data is stored in variables in a standard programming language. #contentInt stores the int interpretation of data, #contentLongHex stores long int/memory address  (*which in turn will make the BaseAddress as a pointer to this memory address*)  interpretation of the data and so on.
class ProcessManager
{	
public:
	/// Stores PID (process ID) of the process on which operations are to be performed.
	long pID = 0;
	/// BaseAddress stores the starting memory address from whih data is to be read or a write has to be performed.
	long BaseAddress = 0;
	///stores the number of subsequent memory addresses after #BaseAddress (including #BaseAddress) are to be read in order to construct a meaningful data out of a given memory location.
	///#span value is 4 for an int value, 8 for a long int or memory address value and variable (equal to string size) for string value (*for a 64 bit framework*). Furthermore, a larger span value can be used to access the contents of a desired number of memory location.
	long span = 0;
	///Store the data read from the memory addresses akin to how the data is stored in variables in a standard programming language.
	///stores the int interpretation of data
	int contentInt;
	///Store the data read from the memory addresses akin to how the data is stored in variables in a standard programming language.
	///stores the int interpretation of data
	long contentLongInt;
	///Store the data read from the memory addresses akin to how the data is stored in variables in a standard programming language.
	///stores long int/memory address (*which in turn will make the BaseAddress as a pointer to this memory address*)
	long contentLongHex;
	///Store the data read from the memory addresses akin to how the data is stored in variables in a standard programming language.
	///stores the char interpretation of data
	char contentChar;
	///Store the data read from the memory addresses akin to how the data is stored in variables in a standard programming language.
	///stores the string interpretation of data
	string contentString;
	///Creates class ProcessManager with only process ID initialized. 
	///
	/// @param id : PID of the process in which we are interested.
	ProcessManager(long id)
	{
		pID = id;
	}
	///Creates class ProcessManager with process ID, #BaseAddress and #span initialized. 
	///
	/// @param id : PID of the process in which we are interested.
	/// @param BA : Base Memory Address (#BaseAddress) where data is stored.
	/// @param sp : Number of subsequent memory address to be used (#span).
	ProcessManager(long id, long BA, long sp)
	{
		pID = id;
		BaseAddress = BA;
		span = sp;
	}
	void FindBaseAddress(char* Module = NULL);
	void PrintContent();
	char* Read();
	void getContent(char * Module = NULL);
	vector<long> scanProcess(int target);
	vector<long> scanProcess(long target);
	vector<long> scanProcess(string target);
	vector<long> scanProcess(char target);
};
