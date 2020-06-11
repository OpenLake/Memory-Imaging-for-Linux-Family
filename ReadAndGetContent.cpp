#include "ProcessManager.h"
using namespace std;

char* ProcessManager::Read()
{
	struct iovec* local = new struct iovec;
	char* op = new char[span];
	local->iov_base = op;
	local->iov_len = span;
	struct iovec* remote = new struct iovec;
	remote->iov_base = (void*)BaseAddress;
	remote->iov_len = span;
	ssize_t nread;
	nread = process_vm_readv(pID, local, 1, remote, 1, 0);
	if (nread != span)
		cout << "Full Data Read failed due to unaccessibility of a memory location\n";
	return op;
}

void ProcessManager::getContent(char * Module = NULL)
{	
	char* op = Read();
	if(Module=="int")
	{ 	
		if(span>=4)
		{
			string s="";
			for(int i=0;i<4;i++)
			{
				s = ToHex((int)op[i])+s;
			}
			s = "0x" + s;
			contentInt = stoi(s, NULL, 16);
			cout<<dec<<contentInt<<endl; //Comment Line When Not Debugging
		}	
		else
		{
			fprintf(stderr, "Invalid span value\n" );
		}	
	}
	if(Module=="long int"|| Module == "address")
	{
		if(span>=8)
		{
			string s="";
			for(int i=0;i<8;i++)
			{
				s = ToHex((int)op[i])+s;
			}
			contentInt = stol(s, NULL, 16);
			cout<<dec<<contentInt<<endl;//Comment Line When Not Debugging
			cout <<hex<< contentInt << endl;//Comment Line When Not Debugging
		}	
		else
		{
			fprintf(stderr, "Invalid span value\n" );
		}	
	}
		
		if(Module=="char")
	{
		contentChar=op[0];
		cout<<contentChar<<endl;//Comment Line When Not Debugging	
	}
		if(Module=="string")
	{
		string s = "";
		for (int i = 0; i < span; i++)
		{
			s = op[i] + s;
		}
		contentString=s;
		cout<<contentString<<endl;//Comment Line When Not Debugging	
	}
	free(op);
}