#include "ProcessManager.h"
using namespace std;

///Function to store meaningful data in ProcessManager
///
///This function takes memory address-wise data (via character array returned by Read()) and puts it together in a meaningful format like int, long int, address, char or string. This meaningful data gets stored in #contentInt/ #contentLongHex/ #contentString/ #contentChar of its ProcessManager
/// @param Module specifies the form in which data is to be organized in order to deem it meaningful. Module is a string which can take "int", "string", "long int", "address", "char" or "string" as a valid argument.
void ProcessManager::getContent(char * Module)
{	
	char* op = Read();
	if(Module=="int")
	{ 	
		if(span>=4)
		{
			string s="";
			for(int i=0;i<4;i++)
			{
				int x =(int)op[i];
				s = ToHex(x)+s;
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
				int x =(long int)op[i];
				s = ToHex(x)+s;
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
}
