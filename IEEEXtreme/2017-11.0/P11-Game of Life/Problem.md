# Game of Life
You are asked to make an implementation of the [game of life](https://en.wikipedia.org/wiki/Conway's_Game_of_Life) by John Horton Conway on a finite torus board and provide its output after cc iterations.

## Input Format
On the first line of the input there will be three integers n, m (1 ≤ n, m ≤ 25) and c (1 ≤ c ≤ 10^7). n and m give the size of the board and c gives the number of iterations that you must simulate.

On the following n lines there will be m characters, either \* or -, each one representing the value of each cell of the board. \* represents a populated cell and - an unpopulated one.

Please note that the bottom neighbours of the last line are cells in the top line, and the left neighbours of the first column are the cells of the last column.

## Constraints
`1 ≤ n, m ≤ 25`

`1 ≤ c ≤ 10^7`

The numbers to be added can contain up to 10^7 symbols.

## Output Format
On the output there should be n lines of m characters each, which represent the state of the board after c iterations.

## Sample Input
4 6 3  
\------  
\------  
\------  
-\*\*\*--

## Sample Output
--\*---  
\------  
--\*---  
--\*---
