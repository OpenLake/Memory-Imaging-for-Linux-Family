#include "ProcessManager.h"
using namespace std;
///Internal Function to generate 2 digit hex string from a given int/other value 
template <typename T>
string ToHex(T i)
{
	stringstream stream;
	stream << hex << i;
	string s = stream.str();
	string ch="";
	//cout << s << endl;
	if (s.length() < 2)
	{
		s = "0" + s;
	}
	if (s.length() > 2)
	{
		ch=s.substr(s.length()-2,2);
		stream.str("");
		return ch;
	}
	stream.str("");
	return s;
}
///Function to read memory addresses signified by ProcessManager individually.
///
///This functions reads every memory address signified by ProcessManager and stores it in a character array which it returns.
/// @note by "every memory address signified by ProcessManager" we mean memory addresses from #BaseAddress to #BaseAddress + #span 
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
///Function to store meaningful data in ProcessManager
///
///This function takes memory address-wise data (via character array returned by Read()) and puts it together in a meaningful format like int, long int, address, char or string. This meaningful data gets stored in #contentInt/ #contentLongHex/ #contentString/ #contentChar of its ProcessManager
/// @param Module specifies the form in which data is to be organized in order to deem it meaningful. Module is a string which can take "int", "string", "long int", "address", "char" or "string" as a valid argument.
void ProcessManager::getContent(string Module)
{	
	char* op = Read();
	if(Module=="int")
	{ 	
		if(span>=4)
		{
			string s="";
			for(int i=0;i<4;i++)
			{
				unsigned int x =(unsigned int)op[i];
				s = ToHex(x)+s;
			}
			s = "0x" + s;
			contentInt = stoul(s, NULL, 16);
			// cout<<hex<<BaseAddress<<":"<<dec<<contentInt<<endl; //Comment Line When Not Debugging
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
				int x =(int)op[i];
				s = ToHex(x)+s;
			}
			s = "0x" + s;
			contentLongInt = stol(s, NULL, 16);
			// cout<<dec<<contentLongInt<<endl;//Comment Line When Not Debugging
			// cout <<hex<< contentLongInt << endl;//Comment Line When Not Debugging
		}	
		else
		{
			fprintf(stderr, "Invalid span value\n" );
		}	
	}
		
		if(Module=="char")
	{
		contentChar=op[0];
		// cout<<contentChar<<endl;//Comment Line When Not Debugging	
	}
		if(Module=="string")
	{
		string s = "";
		for (int i = 0; i < span; i++)
		{
			s = op[i] + s;
		}
		contentString=s;
		// cout<<contentString<<endl;//Comment Line When Not Debugging	
	}
}



