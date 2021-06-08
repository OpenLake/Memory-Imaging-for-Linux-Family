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
2. Run Doxyfile with doxygen , in the terminal while in the toothbrush directory, after completing your work 
 ``` 
 doxygen Doxyfile
```
3. Commit the changes of Doumentation folder in the branch by running the following commands in a sequence
``` 
 git add .
 git commit -m "<your message>"
 git push
```

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

### Creating a PR:

If you want to optimize this project, add features or remove bugs from this project, you are highly encouraged to do so by creating a PR. Your PR would be reviewed by the maintainer and then it depends on maintainer to merge that PR or not.

If you don't know how to create a PR, don't worry. Here is a step-by-step procedure on how to proceed to create a PR.


**#**  Take a look at the existing or create your own issues. A first good issue can be updating README file. Since Open Lake maintainers are generous enough, it is optional to create a issue or wait for a issue to be assigned to you, you can directly create a PR without creating an issue.

**1.**  Fork repository.

**2.**  Open Git Bash.

**3.**  Clone your forked copy of the repositary.

```
git clone <link of your forked repo>
```

**4.** Navigate to the project directory .

```
cd <repo name>
```

**5.** Add a reference(remote) to the original repository.

```
git remote add upstream <original repo link>
```

**6.** Check the remotes for this repository.

```
git remote -v
```

**7.** Always take a pull from the upstream repository to your master branch to keep it at par with the main project(updated repository).

```
git pull upstream master
```

**8.** Create a new branch.

```
git checkout -b <your branch name>
```

**9.** Perform your desired changes to the code base.

**10.** Track your changes .

```
git add . 
```

**11.** Commit your changes .

```
git commit -m "your message"
```

**12.** Push the committed changes in your feature branch to your remote repo.

```
git push -u origin <your branch name>
```

**13.** To create a pull request, click on `compare and pull requests`. Please ensure you compare your feature branch to the desired branch of the repo you are suppose to make a PR to.

**14.** Add appropriate title and description to your pull request explaining your changes. You can see the official PR Format Guidelines [here](https://github.com/OpenLake/Leaderboard-Pro/wiki/PR-Format-Guidelines).

**15.** Click on `Create Pull Request`.

**16.** Congratulations! you have made your PR.

**17.** Now your PR would be reviewed by the maintainer. Sometimes your maintainer would merge your PR request without asking for any further changes. But sometimes your PR might be reviewed to infinity.



