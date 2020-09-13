filesIsPointer =  getAddresses.cpp identifier.cpp main.cpp
filesScanProcesses = Scan.cpp main.cpp
filesGetBaseAddresses = MemoryScan.cpp main.cpp
filesRead = readAndGetContent.cpp main.cpp
filesGetContent = readAndGetContent.cpp main.cpp
rebulildables = *.out
ALL = *.cpp

intro: 
	@echo "\nFuntionalities:\n \nmain \nloop \ndebug \nisPointer \nscanProcesses \ngetBaseAddress \nread \getContent \nclean" 
main: 
	@g++ $(ALL) -o main.out && ./main.out 
loop: 
	cd test/ && g++ loop.cpp -o loop.out && ./loop.out
loopPID:
	ps aux | grep ./loop | grep -v grep
debug: 
	@g++ $(ALL) -o main.out && ./main.out --debug
isPointer: $(filesIsPointer)
	@g++ $(filesIsPointer) -o main.out && ./main.out --debug
scanProcesses: $(filesScanProcesses)
	@g++ $(filesScanProcesses) -o main.out && ./main.out --debug
getBaseAddress: $(filesGetBaseAddresses)
	@g++ $(filesGetBaseAddresses) -o main.out && ./main.out --debug
read: $(filesRead)
	@g++ $(filesRead) -o main.out && ./main.out --debug
getContent: $(filesGetContent)
	@g++ $(filesGetContent) -o main.out && ./main.out --debug
clean: 
	@rm $(rebulildables)