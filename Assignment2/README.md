### For contact main - chananhelman@gmail.com

# Graphs & Operator overloading

This assignment is a continuation of the first assignmet. Here we're gonna add the option for arithmetic options by operator-overloading.

## Graph
The graph in `Graph.cpp` is as in the first assignmet represented as an adjacency matrix, where [i][j] == 0, means no edge between i and j vertices.

## Operators
### The addition operators (+,+=)
1. `+` adding two graphs only if they have the same number of vertices (means the same size). Allwoing as to do:  
`g3 = g1 + g2`

2. `+=` adding to the graph itself another graph in the same size (else throw excpetion).  
Use example: `g1 += g2`

3. `+g` unary **'+'**, returns the graph itself as is.


### The substraction operator (-,-=)
1. `+` adding two graphs only if they have the same number of vertices (means the same size). Allwoing as to do:  
`g3 = g1 - g2`

2. `+=` substracting to the graph itself another graph in the same size (else throw excpetion).  
Use example: `g1 -= g2`

3. `-g` unary **'-'**, switching the sign (like nultiply by -1) of each place that is not 0 (means there is an edge).

### Multiplication operators (* , *=)
We have 2 kinds of multiplication:
1. Multiply 2 graphs ```g1 * g2 ```
multiplying their adjacency matrices, by rules of linear algebra, 
and then initilize all the diagonal to 0, to keep it as a graph format
2. multiplying by a scalar:  
    1. ```g * 2``` 
    2. ``` 2 * g ```

  we want to enbale the two formats. The first one will be a class function, the second to enable it will need to put the function outside the class but in the namespace.  
  This is why:  
  The ```operator*``` function needs to be outside the class because it's a binary operator where the left-hand operand is not of the class type.

In C++, when you define a binary operator as a member function, the left-hand operand must be an object of the class. For example, in the expression ```g1 * 2```, ```g1``` is an object of the Graph class, so you can define operator* as a member function of the Graph class.

However, in the expression ```2 * g1```, ```2``` is not an object of the ```Graph``` class, so you can't define operator* as a member function of the ```Graph``` class. Instead, you need to define ```operator*``` as a non-member function.  
The non-member ```operator*``` function can be a ***friend*** function if it needs to access private or protected members of the Graph class.

### Division operator (/=)
The division operator is defined only on graph with scalar that is not 0.
We're going over the matrix and dividing each edge by this scalar.


### Incerment and decrement - ++prefix & postfix++
- ***prefix*** - allow us to do ```++g``` or ```--g```, increment or decrement by 1, only if the edge is not 0.  
This means we're incrementing (or decreasing) g before we use it or doing function on it.
```g2 = ++g1```  
means ```g2``` will be equal to ```g1``` **after** we've incremented it.

- ***postfix*** - allow us to do ```g++``` or ```g--```, increment or decrement by 1, only if the edge is not 0.  
This means we're incrementing (or decreasing) g after we use it or doing function on it.
```g2 = g1++```  
means ```g2``` will be equal to ```g1``` **before** we've incremented it.

### comparison operator
Lets define first what is the meaning of graph onw is bigger (or smaller) than other graph

1. If g1 is contained in g2, than ```g1 < g2``` 
2.  If not, than ```g1 < g2``` if g2 has more edges than g1
3. If not, than ```g1 < g2```, if g2 is from bigger order, mean has more vertices  

For each other operator such as ```<= or >=```
we'll use logic rules to created them.  
For example to do ```g2 >= g1``` we need
```!(g1 < g2)```


### Equations operators (==,!=)
- 2 graph will be called equal if they are from  the same order (same number of vertices), and they have the same edges and weights between each to vertices.
- If not they are not equal

### Printing by << operator
This operator is not a operation on the graph, but we want to have an access to graph private members. For that we'll use ***friend*** keyword - means it is not part of the class members-functions, but it has the access to the private (or protecred) members.
The function signature will be by using ```ostream``` from standart library - ```std```
``` cpp
friend std::ostream &operator<<(std::ostream &os, const Graph &g);
```
This will allow us to print the graph by this option:  
``` cpp
cout << g1;
```
The printing of the graph will be simple print of the adjacency matrix.
## Algorithms
We have included also our `algorithms.cpp` for checking them after using the operators on the graphs.  
To keep it simple here, a unsymetric graph will be set as a directed graph, otherwise it will be undirected graph.


## Start working
- To run the code clone first the repository to your own computer.  
```bash
git clone https://github.com/chanan-hash/CPP-Ex1.git
```

- To build and compile the project run the ```make``` command in your teminal and it will run automatically the Demo file

- Be sure you have the right compiler ```clang-9```  or ```clang++```

## Testing
We have a test file by using ```doctest.h```
- Run:

```bash 
make test
```
- Then activate the **test** file

```bash 
./test
```
