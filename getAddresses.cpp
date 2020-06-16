// Takes pID of the process as input and returns the addresses of the first element of 2d array. 
// Also stroes the number of rows in AddressesRows and address of the first elemet in AddressesList,

#include "ProcessManager.h"
using namespace std;
int** ProcessManager :: getAddresses (long unsigned int pID) {
	int fd = 0;
	char FileLocation[1024];
	char ChBaseAddress[1024];
	char* p = NULL;
	sprintf(FileLocation,"/proc/%lu/maps",pID);
	FILE *ptr;
	if ( (ptr = fopen(FileLocation, "r")) == NULL  ) {
		printf( " Error in opening file");
		exit (1);
	}
	ptr = fopen (FileLocation, "r");
	char line [1000];
	int i =0;
	int count =0;
	
	int** AddressesList ;
	AddressesList = new int*[30];
	for(int i =0;i<30;i++) {
		AddressesList[i] = new int[2];
	}
	AddressesList[0][0] = pID;
	AddressesList[0][1] = 0;
	while(fgets(line, sizeof(line), ptr)){
		i++;
		stringstream ss (line);
		char add[35];
		ss >> add;
		char *token = strtok(add, "-");
		char addresses[2][35];
		int j=0;
		while(token !=NULL ){
			strcpy(addresses[j], token);
			token = strtok(NULL, "-");
			j+=1; 
		}
		int binNum1, binNum2;
    	binNum1 = (int)strtol(addresses[0], NULL, 16);
    	binNum2 = (int)strtol(addresses[1], NULL, 16);
    	AddressesList[i][0] = binNum1;
    	AddressesList[i][1] = binNum2;
    	
    }
    fclose(ptr);
    ProcessManager :: Addresses = AddressesList;
    ProcessManager :: AddressesRows = i;
    return AddressesList;
  
}
