#include "ProcessManager.h"
using namespace std;

/// Takes @param testval and returns true if the value stored in @param testval is an address.
bool ProcessManager :: isAddress(long testval) {
		int i =0;
		// cout <<size <<endl;
		while( i < this->AddressesRows ){
			if( *(*(this->Addresses+i)+0) <= testval && testval < *(*(this->Addresses+i)+1)) {
				return true;
			}
		i++;
	}
	return false;
}
