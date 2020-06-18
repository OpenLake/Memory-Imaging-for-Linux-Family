#include"ProcessManager.h"

using namespace std;

void ProcessManager::FindBaseAddress(char* Module)
{
	int fd = 0;
	char FileLocation[1024];
	char ChBaseAddress[1024];
	char* p = NULL;
	sprintf(FileLocation,"/proc/%lu/maps",pID);
	if((fd=open(FileLocation,O_RDONLY))<0)
	{
		fprintf(stderr, "Failed to Open File Location\n");
		exit(EXIT_FAILURE);
	}
	char *FileBuffer = new char[100000];
	if(FileBuffer==NULL)
	{
		fprintf(stderr, "Failure in Memory Allocation\n");
		exit(EXIT_FAILURE);
	}
	memset(FileBuffer, 0, 100000);
	memset(ChBaseAddress, 0, 1024);
	for (int i = 0; read(fd, FileBuffer + i, 1) > 0; i++);
	if(Module!=NULL)
	{
		if((p=strstr(FileBuffer,Module))==NULL)
		{
			fprintf(stderr, "Module Not Found\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if((p=strstr(FileBuffer,"r-xp"))==NULL)
		{
			fprintf(stderr, "Module not Found\n");
			exit(EXIT_FAILURE);	
		}
	}
	while( (*p) != '\n' &&p>=FileBuffer)
	{
		p--;
	}
	p++;
	for(int i=0;*p!='-';i++)
	{
		//if(i==0)
		//{
			//cout << "File start of Base Address =" << ChBaseAddress[i] << endl;//=====================================
		//}
		ChBaseAddress[i] = *p;
		p++;
	}
	BaseAddress = strtol(ChBaseAddress, NULL, 16);
	cout <<"Base Address = "<<(void*)BaseAddress<<endl;//====================================================================
	long x;
	//x = strtol(ChBaseAddress, NULL, 10);
	//cout <<"Base Address(decimal) = "<< x << endl;//======================================================================
	memset(ChBaseAddress, 0, 1024);
	p++;
	for (int i = 0; *p != ' '; i++)
	{
		ChBaseAddress[i] = *p;
		p++;
	}
	cout <<"End Address= " <<(void*)strtol(ChBaseAddress, NULL, 16)<<endl;//=========================================================
	span = strtol(ChBaseAddress, NULL, 16) - BaseAddress;
	cout <<"Span = "<<span << endl;//======================================================================================
	free(FileBuffer);
}
