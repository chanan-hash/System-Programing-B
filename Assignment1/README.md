# Graph Project and algorithms

This project is a simple implementation of a Graph data structure in C++, and simple algorithms on graphs. It supports both directed and undirected graphs.



## Features

- Create a Graph object and specify whether it is directed or undirected.
- Load a graph from a 2D adjacency matrix.
- The adjacency matrix must be square (number of rows equals number of columns).
- If the graph is undirected, the adjacency matrix must be symmetric.

## Classes
We have two leading classes here
1. ```Graph.cpp```
2. ```Algorithms```

### Graph.cpp:
- The main funciton there is the ```loadGraph()```. It getting a matrix and loading it to the graph
- Second function that we had to implement is ```printGraph```, printing the number of vertices and edges in the graph

### Algorithms:
We have in this class 5 main functions
1. ```isConnected``` Checking if a graph is connected (not scc), mean all the vertices have edges. 
For undirected graph we'll use the BFS algorithm. For direct graph the main idea is to use DFS algorithms and checking if from the root of the last tree in the DFS-forest, we can get to all the vertices

2. ```isContainsCycle``` Checking 

## Building
- first clone the reposiroty to yourm here is the commad:
```bash
git clone https://github.com/username/repository.git
```

- To build and compile the project run the ```make``` command in your teminal and it will run automatically the Demo file

- We can check leak memory check if we want by running ```make valgrind```

## Testing
