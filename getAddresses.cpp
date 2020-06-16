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
	
	int** AddressesList = (int**)malloc(30*sizeof(int*));
	for(int i =0;i<30;i++) {
		AddressesList[i] = new int[2];
	}
	i=0;
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
	
    	AddressesList[i][0] = (int)strtol(addresses[0], NULL, 16);
    	AddressesList[i][1]= (int)strtol(addresses[1], NULL, 16);

    	
    }
    fclose(ptr);
    AddressesList = (int**)realloc(AddressesList, (i+1)*sizeof(int*));
    // cout << "i is" << i+1 << endl;
    ProcessManager :: Addresses = AddressesList;
    ProcessManager :: AddressesRows = i+1;
    return AddressesList;
  
}
