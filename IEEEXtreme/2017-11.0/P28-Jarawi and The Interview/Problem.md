# Jarawi and The Interview
Today Jarawi had a job interview for a very important tech company, the interviewer asked him to solve the next problem: 
Given a string s (1 ≤ |s| ≤ 10^6), answer q (1 ≤ q ≤ 5*10^4) queries. For each query he received a string pi (1 ≤ |pi| ≤ 100) and he had to determine the size of the longest suffix of pi which is a **subsequence** of s (a suffix of a string is a **substring** that occurs at the end).

Unfortunately Jarawi could not solve the task, so he wants to know if you can solve it.

## Input Format
The first line contains a string s.  
The second line contains an integer q.  
Each of the next q lines contains a string pi.

## Constraints
* 1 ≤ |s| ≤ 10^6
* 1 ≤ q ≤ 5*10^4
* 1 ≤ |p_i| ≤ 100
* All strings contain only lower case letters of the English alphabet.

## Output Format
For each query you need to print the size of the longest suffix of pi which is a subsequence of s.

## Sample Input
xaybaba  
2  
aaba  
yx  

## Sample Output
4  
1 

## Explanation
The first query is "aaba" which has the next suffixes {"a","ba","aba","aaba"}, all of them are subsequence of "xaybaba", so the longest has size 4.

The second query is "yx" which has the next suffixes {"x", "yx"}, only "x" is subsequence of "xaybaba" and it has size 1.