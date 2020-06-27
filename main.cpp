#include"ProcessManager.h"

using namespace std;

int main(){
	long id,BA;
	cout << "Enter PID of the Process\n";
	cin >> id;
	ProcessManager P(id,0,8);
	vector<long> addresses = P.scanProcess();
	P.getAddresses();
	cout << "Starting mapping..." << endl;
	unordered_map<long, ProcessManager::pointerNode*> map = P.getPointerMap(addresses);
	return 0;
}
// int main()
// {
// 	long id,BA;
// 	int a =1234;
// 	cout << "Enter PID of the Process\n";
// 	cin>>id;

// 	ProcessManager P(id,0,4);
// 	vector <long> v= P.scanProcess(1234);
// 	/*ProcessManager P(id);
// 	P.FindBaseAddress("[stack]");
// 	P.PrintContent();*/
// 	return 0;
// }
// int main()
// {
// 	long id,BA;
// 	cout << "Enter PID of the Process\n";
// 	cin >> id;
// 	ProcessManager P(id);
// 	P.span = 12;
// 	P.FindBaseAddress("[stack]");
// 	P.PrintContent();
// 	// cout << "Enter BaseAddress\n";
// 	// cin >> BA;
// 	// ProcessManager P(id,BA,16);

// 	// P.getContent("int");

// 	char test[16] = "7f4644c29001";
// 	// int **add;
// 	// P.getAddresses();
// 	// // int size ;
// 	// // // size = P.AddressesRows;
// 	// // cout << "span:" << P.span << endl;
// 	// // cout << "Addresses size: "<< P.AddressesRows <<endl;
// 	// P.identifierFunction(test);
// 	// cout <<  P.Addresses  << endl << add <<endl;
// 	return 0;
// }
