#include "ProcessManager.h"
using namespace std;

void ProcessManager :: changeContent(long address, string test ){
    // FILE* mem_file;
    // char memFileName[1024];
    char *memFileName = (char*)malloc(50);
    sprintf(memFileName,"/proc/%lu/mem",pID);
    int mem_file = open(memFileName, O_RDWR);
    if(mem_file == -1 ){
        printf("couldn't open file");
        exit(1);
    }
    char *buf = (char*)malloc(4);
    lseek(mem_file, address, SEEK_SET);
    read(mem_file, buf, 4);
    printf("%s",buf);
    string s = test;
    char const *pchar = s.c_str();
    strncpy(buf,pchar,4);
    lseek(mem_file, address,SEEK_SET);
    if(write(mem_file,buf,4)== -1){
        printf("Couldn't write!!");
        exit(1);
    }
    free(buf);
    free(memFileName);
}

