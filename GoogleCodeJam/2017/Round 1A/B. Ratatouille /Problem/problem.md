 You've discovered it: the ultimate recipe for ratatouille, the famous French dish! You know which ingredients to use, and how many grams of each one to use, in order to make one serving of ratatouille. But you believe that anyone can cook, and so you want to share the recipe with the world... and make some money in the process!

You have ordered some ingredient packages that are easy to ship. Each package contains some amount of one ingredient; different packages may have different amounts even if they contain the same ingredient. For convenience, you ordered the same number of packages of each ingredient.

You would like to use these packages to form as many ratatouille kits as possible to send to customers. A kit consists of exactly one package of each ingredient, and a label with the integer number of servings of ratatouille that the kit makes. Since you do not want to shortchange customers or waste food, each package must contain between 90 and 110 percent (inclusive) of the amount of that ingredient that is actually needed to make the number of servings of ratatouille on the kit's label.

For example, suppose that one serving of ratatouille takes 500 g of tomato and 300 g of onion. Suppose that you have a 900 g package of tomato and a 660 g package of onion. You could form these into a kit that makes two servings of ratatouille. To make two servings, 1000 g of tomato and 600 g of onion are required. Since the 900 g of tomato you have is within [90, 110]% of the 1000 g of tomato required, and the 660 g of onion you have is within [90, 110]% of the 600 g of onion required, this is acceptable. However, you could not say that the kit makes one or three servings of ratatouille, nor could you say that it makes 1.999 servings (the number of servings must be an integer).

Note that there are some sets of packages that could never form a kit. Continuing with our recipe above, if you have a 1500 g package of tomato and an 809 g package of onion, for example, there is no amount of servings that you can make. Three servings would take 1500 g of tomato and 900 g of onion, and the amount of onion is not within the [90, 110]% range. No other integer amount of servings works, either.

You want to share your recipe with as many customers as possible, so you want to produce the maximum number of valid kits. (Of course, each package can be used in at most one kit.) What is the largest number of kits that you can form? Note that you are not required to maximize the total number of servings of ratatouille formed.
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each case consists of the following:

    One line with two integers N: the number of ingredients, and P, the number of packages of each ingredient.
    One line with N integers Ri. The i-th of these represents the number of grams of the i-th ingredient needed to make one serving of ratatouille.
    N more lines of P integers each. The j-th value on the i-th of these lines, Qij, represents the quantity, in grams, in the j-th package of the i-th ingredient.

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum number of kits you can produce, as described above.
Limits

1 ≤ T ≤ 100.
1 ≤ Ri ≤ 106, for all i.
1 ≤ Qij ≤ 106, for all i and j.
Small dataset

1 ≤ N ≤ 2.
1 ≤ P ≤ 8.
Large dataset

1 ≤ N ≤ 50.
1 ≤ P ≤ 50.
N × P ≤ 1000.

Sample

Input

6
2 1
500 300
900
660
2 1
500 300
1500
809
2 2
50 100
450 449
1100 1101
2 1
500 300
300
500
1 8
10
11 13 17 11 16 14 12 18
3 3
70 80 90
1260 1500 700
800 1440 1600
1700 1620 900

Output 

Case #1: 1
Case #2: 0
Case #3: 1
Case #4: 0
Case #5: 3
Case #6: 3

Explanation

Note that the last sample case would not appear in the Small dataset.

Sample cases #1 and #2 are the ones described in the problem statement.

In sample case #3, you can form a kit out of the 450 g package of the first ingredient and the 1100 g package of the second ingredient, and say that the kit makes 10 servings of ratatouille. That number of servings requires 500 g of the first ingredient; you have 450 g, which is 90% of 500 and within the allowed limit. It requires 1000 g of the second ingredient; you have 1100 g, which is 110% of 1000 and within the allowed limit.

Once you form this kit, however, you cannot form the remaining packages into a kit. 449 g of the first ingredient and 1101 g of the second ingredient would not be able to form 10 (or any other number of) servings. In fact, the (450 g, 1100 g) kit is the only kit that can be formed from these packages.

In sample case #4, no kits can be formed. Note that the recipe requires particular amounts of particular ingredients in the given order; the ingredients are not interchangeable. This is fine French cuisine, after all!

In sample case #5, the recipe has only one ingredient — how elegantly simple! A single serving cannot use more than 11 g, and two servings cannot use fewer than 18 g. It is possible to form three kits: two with an 11 g package, and one with an 18 g package.

In sample case #6, you can form three valid kits: (700 g, 800 g, 900 g), which makes 10 servings, and (1500 g, 1600 g, 1700 g) and (1260 g, 1440 g, 1620 g), each of which makes 20 servings. Note that you could also say that the (1260 g, 1440 g, 1620 g) kit makes 17, 18, or 19 servings, but it does not matter how many servings a kit makes as long as the kit is valid. 
