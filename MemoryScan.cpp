#include"ProcessManager.h"

using namespace std;
///Debugging Utility 1
///
///This function accesses maps file of a given process ID (pID) and fetches the first memory address of the given *Module*. This memory address gets stored in BaseAddress of class Processmanager.
/// #span of ProcessManager is also initialized in this function which is fetched by subraction of ending memory address (as given in maps file) with BaseAddress.
///Overall this function is useful in generating ProcessManager spanning a single line of maps file if given the appropriate module.
/// @param Module is a string containing information of the line (*function searches for string pattern in maps file*) of which ProcessManager is to be generated. 
/// @note If @param Module is given a permission like *r-xp*, it will generate ProcessManager of the first line with the given permission.  
///@note Default value of @param Module is "r-xp".
void ProcessManager::FindBaseAddress(char* Module)
{
	int fd = 0;
	char FileLocation[1024];
	char ChBaseAddress[1024];
	char* p = NULL;
	sprintf(FileLocation,"/proc/%lu/maps",pID);
	if((fd=open(FileLocation,O_RDONLY))<0)
	{
		fprintf(stderr, "Failed to Open File Location\n");
		exit(EXIT_FAILURE);
	}
	char *FileBuffer = new char[100000];
	if(FileBuffer==NULL)
	{
		fprintf(stderr, "Failure in Memory Allocation\n");
		exit(EXIT_FAILURE);
	}
	memset(FileBuffer, 0, 100000);
	memset(ChBaseAddress, 0, 1024);
	for (int i = 0; read(fd, FileBuffer + i, 1) > 0; i++);
	if(Module!=NULL)
	{
		if((p=strstr(FileBuffer,Module))==NULL)
		{
			fprintf(stderr, "Module Not Found\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if((p=strstr(FileBuffer,"r-xp"))==NULL)
		{
			fprintf(stderr, "Module not Found\n");
			exit(EXIT_FAILURE);	
		}
	}
	while( (*p) != '\n' &&p>=FileBuffer)
	{
		p--;
	}
	p++;
	for(int i=0;*p!='-';i++)
	{
		//if(i==0)
		//{
			//cout << "File start of Base Address =" << ChBaseAddress[i] << endl;//=====================================
		//}
		ChBaseAddress[i] = *p;
		p++;
	}
	BaseAddress = strtol(ChBaseAddress, NULL, 16);
	cout <<"Base Address = "<<(void*)BaseAddress<<endl;//====================================================================
	long x;
	//x = strtol(ChBaseAddress, NULL, 10);
	//cout <<"Base Address(decimal) = "<< x << endl;//======================================================================
	memset(ChBaseAddress, 0, 1024);
	p++;
	for (int i = 0; *p != ' '; i++)
	{
		ChBaseAddress[i] = *p;
		p++;
	}
	cout <<"End Address= " <<(void*)strtol(ChBaseAddress, NULL, 16)<<endl;//=========================================================
	span = strtol(ChBaseAddress, NULL, 16) - BaseAddress;
	cout <<"Span = "<<span << endl;//======================================================================================
	free(FileBuffer);
}
///Debugging Utility 2
///
///This functions prints out all the content stored in memory location BaseAddress and its subsequent memory addresses (till memory location #BaseAddress + #span) in hex.
///@note Format of Print is: "Memory Location(in Hex): Content(in Hex)"
void ProcessManager::PrintContent()
{
	struct iovec *local = new struct iovec;
	char* op = new char[span];
	local->iov_base = op;
	local->iov_len = span;
	struct iovec *remote =new struct iovec;
	remote->iov_base =(void*)BaseAddress;
	remote->iov_len = span;
	ssize_t nread;
	nread = process_vm_readv(pID, local, 1, remote, 1, 0);
	for (int i = 0;i<nread;i++)
	{
		cout <<(void*)(BaseAddress+i)<<": "<< hex << (int)op[i]<<endl;
	}
	if (nread != span)
		cout << "Full Data Read failed due to unaccessibility of a memory location\n";
	free(op);
}

// int main()
// {
// 	long id,BA;
// 	cout << "Enter PID of the Process\n";
// 	cin >> id;
// 	/*ProcessManager P(id);
// 	P.FindBaseAddress("[stack]");
// 	P.PrintContent();*/
// 	cout << "Enter BaseAddress\n";
// 	cin >> BA;
// 	ProcessManager P(id,BA,4);
// 	P.getContent("int");
// 	return 0;
// }
