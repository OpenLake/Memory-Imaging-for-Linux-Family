#include <iostream> 
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <string.h>
using namespace std;

int main () {
	int add;
	long unsigned int  pID ;
	cin >> pID ;
	char test[16] = "7ffd3b993010";
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
		int binNum1, binNum2, testval;
    	binNum1 = (int)strtol(addresses[0], NULL, 16);
    	binNum2 = (int)strtol(addresses[1], NULL, 16);
		testval = (int)strtol(test, NULL,16);
    	if(binNum1 < binNum2) {	
			if( binNum1 < testval && testval < binNum2) {
				cout << "Its there! \n";
				printf("Address Stored: %p \n", test);
				count +=1;
			}
		}
		else {
			if( binNum2 < testval && testval < binNum1) {
				cout << "Its there \n";
				count+=1;
			}
		}
		// cout << addresses[0] << ":"<< addresses[1]<< endl;
	}
	if(count==0) {
		cout << "it isnt here!";
	}
	fclose(ptr);
    return 0;
}