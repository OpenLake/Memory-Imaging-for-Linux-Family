#include "ProcessManager.h"

ProcessManager::ProcessManager(uint32_t pid){
    pID = pid;
    long res = ptrace(PTRACE_ATTACH, pID);
    if(res < 0){
        std::cout<<"Cannot attach to the specified process.";
        exit(-1);
    }
    std::cout<<res<<std::endl;
    std::string exe_loc = "/proc//exe";
    exe_loc.insert(6, std::to_string(pid));
    res = ptrace(PTRACE_DETACH, pID);
    if ((exe_handle = open(exe_loc.c_str(), O_RDONLY) < 0 )){
        std::cout<<"Couldn't open the executable file.";
        exit(-1);
    }
    struct stat exe_stats;
    if ( fstat(exe_handle, &exe_stats) < 0 ){
        std::cout<<"Couldn't stat the file";
        exit(-1);
    }
    exe_map = mmap(NULL, exe_stats.st_size, PROT_READ, MAP_PRIVATE, exe_handle, 0x0);
}

ProcessManager::~ProcessManager(){
    if(mem_handle)
        close(mem_handle);
    if(exe_handle)
        close(exe_handle);
}