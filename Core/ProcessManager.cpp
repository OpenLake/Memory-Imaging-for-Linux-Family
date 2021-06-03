#include "ProcessManager.h"

ProcessManager::ProcessManager(uint32_t pid){
    pID = pid;
    long res = ptrace(PTRACE_SEIZE, pID, 0, 0);
    if(res < 0){
        Tools::raise_error("Ptrace unable to attach");
    }
    std::string exe_symlink_loc = "/proc//exe";
    exe_symlink_loc.insert(6, std::to_string(pid));
    char exe_location[2048];
    Tools::read_sym_link(exe_symlink_loc.c_str(), exe_location, sizeof(exe_location));
    std::cout<<exe_location<<std::endl;
    if ((exe_handle = open(exe_location, O_RDONLY) < 0 )){
        Tools::raise_error("Executable open failed");
    }
    if ( fstat(exe_handle, &exe_stats) < 0 ){
        Tools::raise_error("Executable stat failed");
    }
    std::cout<<exe_stats.st_size<<std::endl;
    exe_map = mmap(NULL, exe_stats.st_size, PROT_READ, MAP_PRIVATE, exe_handle, 0);
    if(exe_map == MAP_FAILED){
        Tools::raise_error("mmap failed");
    }
    parse_headers();
}

ProcessManager::~ProcessManager(){
    std::cout<<"And the destructor is called.\n";
    ptrace(PTRACE_CONT, pID);
    ptrace(PTRACE_DETACH, pID);
    close(mem_handle);
    close(exe_handle);
}