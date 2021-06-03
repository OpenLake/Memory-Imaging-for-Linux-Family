#include <filesystem>
#include <unistd.h>
#include <iostream>

namespace Tools {
    void read_sym_link(const char*, char*, size_t);
    void raise_error(const char*);
}