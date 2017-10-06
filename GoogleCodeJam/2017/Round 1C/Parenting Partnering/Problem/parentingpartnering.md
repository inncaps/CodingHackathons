Problem

Cameron and Jamie are longtime life partners and have recently become parents! Being in charge of a baby, exciting as it is, is not without challenges. Given that both parents have a scientific mind, they have decided to take a scientific approach to baby care.

Cameron and Jamie are establishing a daily routine and need to decide who will be the main person in charge of the baby at each given time. They have been equal partners their whole relationship, and they do not want to stop now, so they decided that each of them will be in charge for exactly 12 hours (720 minutes) per day.

Cameron and Jamie have other activities that they either need or want to do on their own. Cameron has AC of these and Jamie has AJ. These activities always take place at the same times each day. None of Cameron's activities overlap with Jamie's activities, so at least one of the parents will always be free to take care of the baby.

Cameron and Jamie want to come up with a daily baby care schedule such that:

Scheduled baby time must not interfere with a scheduled activity. That is, during Cameron's activities, Jamie has to be in charge of the baby, and vice versa.
Each of Cameron and Jamie must have exactly 720 minutes assigned to them.
The number of exchanges — that is, the number of times the person in charge of the baby changes from one partner to the other — must be as small as possible.
For example, suppose that Jamie and Cameron have a single activity each: Jamie has a morning activity from 9 am to 10 am, and Cameron has an afternoon activity from 2 pm to 3 pm. One possible but suboptimal schedule would be for Jamie to take care of the baby from midnight to 6 am and from noon to 6 pm, and for Cameron to take care of the baby from 6 am to noon and 6 pm to midnight. That fulfills the first two conditions, and requires a total of 4 exchanges, which happen at midnight, 6 am, noon and 6 pm. If there is an exchange happening at midnight, it is counted exactly once, not zero or two times.

A better option would be for Cameron to take care of the baby from midnight to noon, and Jamie to take care of the baby from noon to midnight. This schedule also fulfills the first two conditions, but it uses only 2 exchanges, which is the minimum possible.

Given Cameron's and Jamie's lists of activities, and the restrictions above, what is the minimum possible number of exchanges in a daily schedule?

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case starts with a line containing two integers AC and AJ, the number of activities that Cameron and Jamie have, respectively. Then, AC + AJ lines follow. The first AC of these lines contain two integers Ci and Di each. The i-th of Cameron's activities starts exactly Ci minutes after the start of the day at midnight and ends exactly Di minutes after the start of the day at midnight (taking exactly Di - Ci minutes). The last AJ of these lines contain two integers Ji and Ki each, representing the starting and ending time of one of Jamie's activities, in minutes counting from the start of the day at midnight (same format as Cameron's). No activity spans two days, and no two activities overlap (except that one might end exactly as another starts, but an exchange can still occur at that time).

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y the minimum possible number of exchanges, as described in the statement.

Limits

1 ≤ T ≤ 100.
0 ≤ Ci < Di ≤ 24 × 60, for all i.
0 ≤ Ji < Ki ≤ 24 × 60, for all i.
Any two of the intervals of {[Ci, Di) for all i} union {[Ji, Ki) for all i} have an empty intersection. (The intervals are closed on the left and open on the right, which ensures that two exactly consecutive intervals have nothing in between but do not overlap.)
sum of {Di - Ci for all i} ≤ 720.
sum of {Ki - Ji for all i} ≤ 720.
Small dataset

0 ≤ AC ≤ 2.
0 ≤ AJ ≤ 2.
1 ≤ AC + AJ ≤ 2.
Large dataset

0 ≤ AC ≤ 100.
0 ≤ AJ ≤ 100.
1 ≤ AC + AJ ≤ 200.
Sample


Input 
 	
Output 
 
5
1 1
540 600
840 900
2 0
900 1260
180 540
1 1
1439 1440
0 1
2 2
0 1
1439 1440
1438 1439
1 2
3 4
0 10
1420 1440
90 100
550 600
900 950
100 150
1050 1400

Case #1: 2
Case #2: 4
Case #3: 2
Case #4: 4
Case #5: 6

Note that Sample Cases #4 and #5 would not appear in the Small dataset.

Sample Case #1 is the one described in the problem statement.

In Sample Case #2, Jamie must cover for all of Cameron's activity time, and then Cameron must cover all the remaining time. This schedule entails four exchanges.

In Sample Case #3, there is an exchange at midnight, from Cameron to Jamie. No matter how the parents divide up the remaining 1438 non-activity minutes of the day, there must be at least one exchange from Jamie to Cameron, and there is no reason to add more exchanges than that.

In Sample Case #4, note that back-to-back activities can exist for the same partner or different partners. There is no exchange at midnight because Cameron has activities both right before and right after that time. However, the schedule needs to add some time for Cameron in between Jamie's activities, requiring a total of 4 exchanges. Notice that it is optimal to add a single interval for Cameron of length 718 somewhere between minutes 2 and 1438, but the exact position of that added interval does not impact the number of exchanges, so there are multiple optimal schedules.

In Sample Case #5, a possible optimal schedule is to assign Cameron to the intervals (in minutes) 100-200, 500-620, and 900-1400.
