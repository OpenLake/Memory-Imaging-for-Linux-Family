#include"ProcessManager.h"

using namespace std;


int main()
{
	long id,BA;
	cout << "Enter PID of the Process\n";
	cin >> id;
	ProcessManager P(id);
	P.span = 12;
	P.FindBaseAddress("[stack]");
	P.PrintContent();
	// cout << "Enter BaseAddress\n";
	// cin >> BA;
	// ProcessManager P(id,BA,16);

	// P.getContent("int");

	char test[16] = "7f4644c29001";
	// int **add;
	// P.getAddresses();
	// // int size ;
	// // // size = P.AddressesRows;
	// // cout << "span:" << P.span << endl;
	// // cout << "Addresses size: "<< P.AddressesRows <<endl;
	// P.identifierFunction(test);
	// cout <<  P.Addresses  << endl << add <<endl;
	return 0;
}
