#include"ProcessManager.h"

using namespace std;


void ProcessManager::PrintContent()
{
	struct iovec *local = new struct iovec;
	char* op = new char[span];
	local->iov_base = op;
	local->iov_len = span;
	struct iovec *remote =new struct iovec;
	remote->iov_base =(void*)BaseAddress;
	remote->iov_len = span;
	ssize_t nread;
	nread = process_vm_readv(pID, local, 1, remote, 1, 0);
	for (int i = 0;i<nread;i++)
	{
		cout <<(void*)(BaseAddress+i)<<": "<< hex << (int)op[i]<<endl;
	}
	if (nread != span)
		cout << "Full Data Read failed due to unaccessibility of a memory location\n";
	free(op);
}

