#include "ProcessManager.h"
using namespace std;
///Internal Function to generate 2 digit hex string from a given int/other value 
template <typename T>
string ToHex(T i)
{
	stringstream stream;
	stream << hex << i;
	string s = stream.str();
	//cout << s << endl;
	if (s.length() < 2)
	{
		s = "0" + s;
	}
	if (s.length() > 2)
	{
		return "";
	}
	stream.str("");
	return s;
}