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


using namespace std;
typedef unsigned int uint;

class ProcessManager
{	
public:
	long pID = 0;
	long BaseAddress = 0;
	long span = 0;
	int contentInt;
	long contentLongInt;
	long contentLongHex;
	char contentChar;
	string contentString;
	ProcessManager(long id)
	{
		pID = id;
	}
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
};

