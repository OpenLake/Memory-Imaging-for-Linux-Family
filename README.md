# Memory Imaging for Linux Family

Memory Imaging for Linux Family by OpenLake scans through the virtual memory of a specified application running on Linux based distros.This utility can be used in monitoring and isolating a desired value that the application uses. Furthermore the functions in the software can be used to explore how different applications are managing their data in the memory and can be used to chalk out the classes and objects used by the applications.

## Completed Features
1. Isolation of starting address based on the identifying string (module) in the maps file for a given pid.
2. Raw read of contents in each memory address of maps file for a given pid.
3. Searching for a given integer, string, character and pointer value in the virtual memory for a given pid.
4. Narrowing the search by changing value of variables.
5. Generating pointer mapping to bring out memorywise rough structure of a given application.

## Developement of following features are under progress:
1. Commandline interface
2. Debug Utilities
3. Identifying static memory addresses
4. Changing the value at a given virutal memory address
5. Support for android devices (rooted)
6. Standardizing data types

## Viewing Documentation:

Open index.html in Documentation/html to view the documentation.
  
### Documentation Instructions:
1. Install doxygen by running the following command:
``` 
sudo apt-get install doxygen
```
2. Run Doxyfile with doxygen (type "doxygen Doxyfile" in the terminal while in the toothbrush directory) after completing your work
 ``` 
 doxygen Doxyfile
```
3. Commit the changes of Doumentation folder in the branch

### How to document:
In short the config file that I have made will read the comment in the format:
/// Brief overview of function or class <br>
/// <br>
///Detailed description of function or class <br>
/// @param FunctionParameter details of FunctionParameter <br>
/// #classMember yada yada <br>
Do note that these comments are to be included before the class or function to be described <br>
For more details see comments in files of branch DocumentationSupport while viewing index.html in documentation folder <br>
For more refer relevant sections of the [video](https://www.youtube.com/watch?v=TtRn3HsOm1s) 

