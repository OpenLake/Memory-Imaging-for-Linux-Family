#include "ProcessManager.h"
using namespace std;

char* ProcessManager::Read()
{
	struct iovec* local = new struct iovec;
	char* op = new char[span];
	local->iov_base = op;
	local->iov_len = span;
	struct iovec* remote = new struct iovec;
	remote->iov_base = (void*)BaseAddress;
	remote->iov_len = span;
	ssize_t nread;
	nread = process_vm_readv(pID, local, 1, remote, 1, 0);
	if (nread != span)
		cout << "Full Data Read failed due to unaccessibility of a memory location\n";
	return op;
}
