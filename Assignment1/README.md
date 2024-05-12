### For contact you can wirte me a mail - chananhelman@gmail.com

# Graph and algorithms Project

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
- The main funciton there is the ```loadGraph```. It getting a matrix and loading it to the graph
- Second function that we had to implement is ```printGraph```, printing the number of vertices and edges in the graph

### Algorithms:
We have in this class 5 main functions
1. ```isConnected``` Checking if a graph is connected (not scc), mean all the vertices have edges.  
For undirected graph we'll use the **BFS** algorithm.  
For direct graph the main idea is to use **DFS** algorithms and checking if from the root of the last tree in the ***DFS-forest*** , we can get to all the vertices

2. ```isContainsCycle``` Checking if A graph has cycle. We're using the DFS algorithm, and kind of checking what edge is it (tree,back,forward or cross edge)
In undirected graph we only tree edge, and back edge, it will be marked by boolean vector, and if in the DFS visited we got back to vertex we've visited means there is cycle  
For directed graph will use a vector of color (that are defined as number), if we have found while running DFS a back-edge means we have cycle, in the code it means we've got again to GRAY colored vertex
3. ```shortedPath``` For finding the shortes path we'll check the kind of the graph:  
    1. **BFS** - for unweited graph
    2. **Dijkstra** - for positive weighted graph
    3. **Bellman** - Ford for graph with negative weights

4. ```negativeCycle``` This function return the actual negative cycle if found.  
IN undirected graph, if we have a negative edge we'll make it as a negative-cycle, although it is not an actuall cycle, because the idea of negative-cycle, is to reduce the value of the path

5. ```isBipartite``` This function checking if we can divdie the graph into two groups, that inside each group there is no edge between them.  
The main idea is to use **BFS** algorithm and to try coloring the graph with 2 colors, and check if each vertex and it's neighbors with different colors

## Building
- First clone the reposiroty to your on computer, here is the commad:
```bash
git clone https://github.com/chanan-hash/CPP-Ex1.git
```

- To build and compile the project run the ```make``` command in your teminal and it will run automatically the Demo file

- Be sure you have the right compiler ```clang-9```  or ```clang++```

## Testing
By using ```doctest.h``` file, we'vr creted  a test file that checks the function on all kind of graph such as, directed/undirected, big/small, connected/unconected, empty, invalid, with and whitout cycles, etc...  
To run the test after cloning the repository use ```make test``` command, and then run ```./test``` and it will run the test file

## Valgrind
For checking memory leak we can compile this project by writing in the terminal ```make vlagrind```
