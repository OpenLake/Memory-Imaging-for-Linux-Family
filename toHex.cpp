#include "ProcessManager.h"
using namespace std;

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