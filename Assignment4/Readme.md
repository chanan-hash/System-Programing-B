# TREE GUI AND ITERATORS

In this project we are creating a tree graph that can be in default a `binary tree` or a   `k-tree` means that each childe has not more than k children.

## Classes
### Node class
### Tree class

## Iterators

## Runing the project
To run this project at first clone this repo
```bash
git clone 
```

Then you should ensure that you have g++ compiler. if not you can installl it with all `c` and `c++` needed
```bash
sudo apt-get update
sudo apt-get install build essential
``` 
allso check that you have `valgrind` installed
```bash
sudo apt install valgrind
```
**For gui to show the tree we've used `SFML`.**  
You must have it that the project can run.  You can instaal it by this command:
```bash
sudo apt-get install libsfml-dev
```
### Runing the groject itself
After you have all the packges
we can run the project
run `make`
if will compile everything
then to run the project run:
`./tree`  
and the program will run.
It will show you the tree in a window, and prints in the terminal of all the iterators.
For each tree it will open a window, so to see the next tree you need to close the current window, and automatically it will open the next one.  
Here is example of what you'll see:

### Test
For testing our program we've used `doctest.h`.
To run the test just write
`make test` and it'll run the test automatically