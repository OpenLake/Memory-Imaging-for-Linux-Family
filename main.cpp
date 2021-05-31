#include "Core/ProcessManager.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <elf.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdint.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>

//[TODO]: Move the argparse & options section to its own file & add docs
struct Options{
	bool help = false;
	//change to (int)verbosity level in future if project becomes too big
	bool verbose = false;
	int process_id = -1;
	bool scan = false;
	bool info = true;
};

//[TODO] : Add docs
Options argparse(int argc, char **argv){
	Options args;
	for (int i=1; i<argc; i++){
		if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")){
			args.help = true;
			break;
		}
		if(!strcmp(argv[i], "-v") || !strcmp(argv[i], "--verbose")){
			args.verbose = true;
			continue;
		}
		if( !strcmp(argv[i], "-p")){
			if(argc < i+2) {
				printf("No process ID specified!");
				break;
			}
			else {
				args.process_id = std::stoi(argv[i+1]);
				continue;
			}
		}
		//[TODO] : Add more options as the project improves
	}
	return args;
}

int main(int argc, char **argv){

	if (argc<2){
		printf("Read docs doofus! Try with -h or --help\n");
		return 0;
	}
	Options args = argparse(argc, argv);
	if(args.help){
		printf("Usage :\n\tmilf [options] -p [PID_of_process]\nOptions :\n\t-v : Verbose output\n");
	}
	if(args.process_id != -1){
		ProcessManager manager = ProcessManager(args.process_id);
	}
	printf("[TODO] : Perform the actions specified based on the args.\n");
}