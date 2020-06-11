using namespace std;
typedef unsigned int uint;

class ProcessManager
{	
public:
	long pID = 0;
	long BaseAddress = 0;
	long span = 0;
	ProcessManager(long id)
	{
		pID = id;
	}
	void FindBaseAddress(char* Module = NULL);
	void PrintContent();
};

