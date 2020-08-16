filesIsPointer =  getAddresses.cpp identifier.cpp main.cpp
filesScanProcesses = Scan.cpp main.cpp
filesGetBaseAddresses = MemoryScan.cpp main.cpp
filesRead = readAndGetContent.cpp main.cpp
filesGetContent = readAndGetContent.cpp main.cpp
rebulildables = main 
ALL = *.cpp

main: 
	@g++ $(ALL) -o main && ./main --debug
intro: 
	@echo "\nFuntionalities:\n \nisPointer \nscanProcesses \ngetBaseAddress \nread \getContent \nclean" 
isPointer: $(filesIsPointer)
	@g++ $(filesIsPointer) -o main && ./main
scanProcesses: $(filesScanProcesses)
	@g++ $(filesScanProcesses) -o main && ./main
getBaseAddress: $(filesGetBaseAddresses)
	@g++ $(filesGetBaseAddresses) -o main && ./main
read: $(filesRead)
	@g++ $(filesRead) -o main && ./main 
getContent: $(filesGetContent)
	@g++ $(filesGetContent) -o main && ./main
clean: $(rebulildables)
	@rm $(rebulildables)