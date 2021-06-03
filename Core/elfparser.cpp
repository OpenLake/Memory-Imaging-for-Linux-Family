#include "ProcessManager.h"

bool check_magic(Elf64_Ehdr* header){
#define em header->e_ident
    if ( em[0] == ELFMAG0 && em[1] == ELFMAG1 && em[2] == ELFMAG2 && em[3] == ELFMAG3){
#undef em
        return true;
    }
    std::cout<<"ELF magic verified!";
    return false;
};

void ProcessManager::parse_headers(){
    Elf64_Ehdr* elf_header = (Elf64_Ehdr*)exe_map;
    check_magic(elf_header);
}