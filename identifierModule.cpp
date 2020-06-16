// Takes pID, testval(int) and addresses list as input and returns the address stored if  testval is a pointer.
#include "ProcessManager.h"
using namespace std;

void ProcessManager :: identifierFunction(long unsigned int pid, int testval, int** add) {
		// int testval = (int)strtol(test, NULL,16);
		int i =1;
		int count=0;
		while( i < 30){
    	if(add[i][0] < add[i][1]) {	
			if( add[i][0] < testval && testval < add[i][1]) {
				cout << "Its there! \n";
				printf("Address Stored: %p \n", test);
				count +=1;
			}
		}
		else {
			if( add[i][1] < testval && testval < add[i][0]) {
				cout << "Its there \n";
				count+=1;
			}
		}
		i++;
	}
	if(count==0) {
		cout << "it isnt here!";
	}
	
	
}