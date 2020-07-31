#include"ProcessManager.h"

using namespace std;


int main()
{
	long id,BA;
	int a =1234;
	cout << "Enter PID of the Process\n";
	cin>>id;

	ProcessManager P(id,0,4);
	vector <long> v= P.scanProcess(1234);
	/*ProcessManager P(id);
	P.FindBaseAddress("[stack]");
	P.PrintContent();*/
	return 0;
}
