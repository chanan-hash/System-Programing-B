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

### Division operator (/=)

### Incerment and decrement - prefix & postfix

### comparison operator

### Printing by << operator


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


- שישה אופרטורי השוואה: גדול, גדול-או-שווה, קטן, קטן-או-שווה, שווה, לא-שווה. לשם מטלה זו כללי השוואת גרפים הם כדלקמן:

  1. גרפים G1 ו-G2 ייקראו שווים אם הם מאותו סדר גודל ומכילים את אותן הצלעות (והמשקלים של הצלעות זהים) או אם G1 לא גדול מ-G2 וגם G2 לא גדול מ-G1.
  2. גרף G2 גדול מגרף G1 אם הגרף G1 מוכל ממש בגרף G2. אם אף גרף לא מוכל ממש בשני והגרפים לא שווים, אז גרף G2 גדול מגרף G1 אם מספר הצלעות ב-G2 גדול ממספר הצלעות ב-G1. אם בכל זאת מספר הצלעות זהה, אז הגרף G2 גדול מהגרף G1 אם המטריצה המייצגת של G2 בעלת סדר גודל גבוה יותר משל G1.

- הגדלה ב-1 (++) והקטנה ב-1 (--) לפני ואחרי המספר. פעולה זו תגדיל או תקטין ב-1 את כל המשקלים של הצלעות בגרף.
- הכפלה בסקלר שלם (`int`) - מכפיל את המשקל של כל הצלעות.
- הכפלת גרפים - אנחנו מגדירים את פעולת הכפל בין גרף G1 לגרף G2 על ידי מכפלה של המטריצות המייצגות של שני הגרפים. התוצאה צריכה להיות מטריצה המייצגת גרף. ניסיון לבצע כפל בין גרפים בגדלים שונים צריך לזרוק שגיאה.
- אופרטור פלט - הדפסה הגיונית של הגרף (צורת ההפדסה היא לשיקולכם).

