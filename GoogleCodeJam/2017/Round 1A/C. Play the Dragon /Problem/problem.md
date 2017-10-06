 You are a friendly dragon fighting to protect your lair from a greedy knight! You have Hd health points and an attack power of Ad, and the knight has Hk health points and an attack power of Ak. If your health drops to 0 or below at any point; you are knocked out and you instantly lose; if the knight's health drops to 0 or below at any point, the knight is knocked out and you win!

You will battle the knight in a series of turns. On each turn, you go first, and you can choose and execute any one of the following actions.

    Attack: Reduce the opponent's health by your own attack power.
    Buff: Increase your attack power by B for the rest of the battle.
    Cure: Your health becomes Hd.
    Debuff: Decrease the opponent's attack power by D for the rest of the battle. If a Debuff would cause the opponent's attack power to become less than 0, it instead sets it to 0.

Then, if the knight's health is greater than 0 following your action, the knight will execute an Attack action. After that, the turn ends. (Note that a turn in which you defeat the knight still counts as a turn even though the knight does not get to act.)

Note that buffs stack with each other; every buff adds an additional B to your attack power. Similarly, debuffs stack with each other.
You would like to defeat the knight as fast as possible (if it is possible) so that you will not be late to help the villagers roast marshmallows at tonight's festival. Can you determine the minimum number of turns in which you can defeat the knight, or that it is IMPOSSIBLE to do so?

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each consists of one line with six integers Hd, Ad, Hk, Ak, B, and D, as described above.
Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is either IMPOSSIBLE if it is not possible to defeat the knight, or the minimum number of turns needed to defeat the knight.
Limits

1 ≤ T ≤ 100.
Small dataset

1 ≤ Hd ≤ 100.
1 ≤ Ad ≤ 100.
1 ≤ Hk ≤ 100.
1 ≤ Ak ≤ 100.
0 ≤ B ≤ 100.
0 ≤ D ≤ 100.
Large dataset

1 ≤ Hd ≤ 109.
1 ≤ Ad ≤ 109.
1 ≤ Hk ≤ 109.
1 ≤ Ak ≤ 109.
0 ≤ B ≤ 109.
0 ≤ D ≤ 109.

Sample

Input 

4
11 5 16 5 0 0
3 1 3 2 2 0
3 1 3 2 1 0
2 1 5 1 1 1

Output 

Case #1: 5
Case #2: 2
Case #3: IMPOSSIBLE
Case #4: 5

Explanation

 In Case #1, you have 11 health and 5 attack, and the knight has 16 health and 5 attack. One possible optimal sequence of actions is:

    Turn 1: Attack, reducing the knight's health to 11. Then the knight attacks and reduces your health to 6.
    Turn 2: Attack, reducing the knight's health to 6. Then the knight attacks and reduces your health to 1.
    Turn 3: Cure, restoring your health to 11. Then the knight attacks and reduces your health to 6. (If you had attacked instead this turn, the knight's next attack would have caused you to lose.)
    Turn 4: Attack, reducing the knight's health to 1. Then the knight attacks and reduces your health to 1.
    Turn 5: Attack, reducing the knight's health to -4. You instantly win and the knight does not get another attack.

In Case #2, one possible optimal sequence of actions is:

    Turn 1: Buff, increasing your attack power to 3. Then the knight attacks and reduces your health to 1.
    Turn 2: Attack, reducing the knight's health to 0. You instantly win and the knight does not get another attack.

In Case #3, the knight only needs two attacks to defeat you, and you cannot do enough damage fast enough to defeat the knight. You can indefinitely extend the combat by executing the Cure action after every attack, but it is impossible to actually defeat the knight.

In Case #4, one possible optimal sequence of actions is: Attack, Debuff, Buff, Attack, Attack. 
