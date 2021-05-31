/// This function stores the address of a 2D array containing the base and end addresses of each continuous 
///memory in maps file
/// Also stores the number of rows in maps files in AddressesRows and address of the first elemet in AddressesList,

#include "ProcessManager.h"
using namespace std;
void ProcessManager :: getAddresses () {
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
	char line [200];
	int i =0;
	int count =0;
	while (fgets(line, sizeof(line), ptr)){
		count++;
	}
	 ProcessManager :: AddressesRows = count+1;
	rewind(ptr);
	int** AddressesList = new int*[count+1];
	for(int i =0;i<count+1;i++) {
		AddressesList[i] = new int[2];
	}
	while(fgets(line, sizeof(line), ptr)){
		i++;
		stringstream ss (line);
		char add[span*2 +2];
		ss >> add;
		char *token = strtok(add, "-");
		char addresses[2][span+1];
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
    // cout << "i is" << i+1 << endl;
    ProcessManager :: Addresses = AddressesList;
   

  
}
