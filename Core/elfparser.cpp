#include "ProcessManager.h"

bool check_magic(unsigned char *exe_map){

#define em exe_map
    if ( em[0] == ELFMAG0 && em[1] == ELFMAG1 && em[2] == ELFMAG2 && em[3] == ELFMAG3){
#undef em
        return true;
    }
    return false;
    Elf64_Ehdr;
};

void ProcessManager::parse_headers(){
    if (!check_magic((unsigned char *)exe_map)){
        std::cout<<"The file is not a valid ELF.\n";
        exit(-1);
    }

}