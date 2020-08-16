#include"ProcessManager.h"

using namespace std;


int main(int argc, char* argv[])
{
	
	long id,BA;
	int a =1234;
	cout << "Enter PID of the Process\n";
	cin >> id;
	// ProcessManager P(id);
	// P.span = 12;
	// P.FindBaseAddress("[stack]");
	// P.PrintContent();
	// // cout << "Enter BaseAddress\n";
	// // cin >> BA;
	// // ProcessManager P(id,BA,16);
	// P.debug = false;
	ProcessManager P(id,0,4);
	if (argv[argc-1] == "--debug"){
		P.debug = true;
	}
	// vector <long> v= P.scanProcess(1234);
	
	// cin>>id;

	// ProcessManager P(id,0,4);
	// vector <long> v= P.scanProcess(1234);
	/*ProcessManager P(id);
	P.FindBaseAddress("[stack]");
	P.PrintContent();*/
	return 0;
}
