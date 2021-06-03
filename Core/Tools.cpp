#include "Tools.h"

void Tools::read_sym_link(const char* symlink, char* real_path, size_t len){
    ssize_t num_char = readlink(symlink, real_path, len);
    if(num_char<0){
        std::cout<<"Couldn't read symlink : "<<symlink<<std::endl;
        exit(-1);
    }
}

void Tools::raise_error(const char* error_desc){
    perror(error_desc);
    exit(-1);
}