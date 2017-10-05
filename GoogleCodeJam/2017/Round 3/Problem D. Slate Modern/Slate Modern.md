Problem

The prestigious Slate Modern gallery specializes in the latest art craze: grayscale paintings that follow very strict rules. Any painting in the gallery must be a grid with R rows and C columns. Each cell in the grid is painted with a color of a certain positive integer brightness value; to make sure the art is not too visually startling, the brightness values of any two cells that share an edge (not just a corner) must differ by no more than D units.

Your artist friend Cody-Jamal is working on a canvas for the gallery. Last night, he became inspired and filled in N different particular cells with certain positive integer brightness values. You just told him about the gallery's rules today, and now he wants to know whether it is possible to fill in all of the remaining cells with positive integer brightness values and complete the painting without breaking the gallery's rules. If this is possible, he wants to make the sum of the brightness values as large as possible, to save his black paint. Can you help him find this sum or determine that the task is impossible? Since the output can be a really big number, we only ask you to output the remainder of dividing the result by the prime 109+7 (1000000007).

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with one line with four integers: R, C, N, and D, as described above. Then, N lines follow; the i-th of these has three integers Ri, Ci, and Bi, indicating that the cell in the Rith row and Cith column of the grid has brightness value Bi. The rows and columns of the grid are numbered starting from 1.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is either IMPOSSIBLE if it is impossible to complete the picture, or else the value of the maximum possible sum of all brightness values modulo the prime 109+7 (1000000007).

Limits

1 ≤ T ≤ 100.
1 ≤ N ≤ 200.
1 ≤ D ≤ 109.
1 ≤ Ri ≤ R, for all i. 1 ≤ Ci ≤ C, for all i. 1 ≤ Bi ≤ 109, for all i. (Note that the upper bound only applies to cells that Cody-Jamal already painted. You can assign brightness values larger than 109 to other cells.)
N < R × C. (There is at least one empty cell.)
Ri ≠ Rj and/or Ci ≠ Cj for all i ≠ j. (All of the given cells are different cells in the grid.)
Small dataset

1 ≤ R ≤ 200.
1 ≤ C ≤ 200.
Large dataset

1 ≤ R ≤ 109.
1 ≤ C ≤ 109.
Sample


Input&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Output 
 
4&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Case #1: 40<br />
2 3 2 2&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Case #2: 999999986<br />
2 1 4&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Case #3: IMPOSSIBLE<br />
1 2 7&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Case #4: IMPOSSIBLE<br />
1 2 1 1000000000<br />
1 2 1000000000<br />
3 1 2 100<br />
1 1 1<br />
3 1 202<br />
2 2 2 2<br />
2 1 1<br />
2 2 4<br />






In Sample Case #1, the optimal way to finish the painting is:

6 7 9
4 6 8

and the sum is 40.

In Sample Case #2, the optimal way to finish the painting is:

2000000000 1000000000

and the sum is 3000000000; modulo 109+7, it is 999999986.

In Sample Case #3, the task is impossible. No matter what value you choose for the cell in row 2, it will be too different from at least one of the two neighboring filled-in cells.

In Sample Case #4, the two cells that Cody-Jamal filled in already have brightness values that are too far apart, so it is impossible to continue.
