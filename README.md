# Number Chain

## Introduction

Your task is to create a program that reads in pairs of numbers and for each pair prints the shortest sequence of operations that will convert the first number in the pair to the second number in the pair.

The three allowed operations are:

**1) Add a subsequence of digits in the number to the current number.**  
_For example, if the current number is 4245, you could add 4, 2, 5, 42, 24, 45, 424, 245, or 4245 to the number._  
<u>Example</u>: 2625 -> 2687 (2625 + 62)  

**2) Split the number into two parts and multiply them together.**  
_For example, if the current number is 8271, the next number could be 8 * 271 or 82 * 71 or 827 * 1. This is only possible if the number has 2 or more digits._  
<u>Example</u>: 512 -> 60 (5*12)  


**3) Swap two adjacent bits in the number.**  
<u>Example</u>: 6 -> 10 (0110 -> 1010)  
<u>Example</u>: 27 -> 23 (11011 -> 10111)  

## Requirements

Input will be provided as list of pairs of numbers separated with a space, one pair per line. These numbers can be read from standard input or from a file - your choice.

Output should include the number at each step in the number chain, along with the operation that resulted in the number at that step. When specifying the bits that are swapped, bit 0 refers to the least significant bit. At the end you should print the length of the chain, including the starting and ending numbers. If it’s not possible to go from the starting number to the end number, you can print “No solution”. Please refer to the example input/output for details.

Depending on the order that you apply the operations, your output may not match the sample output. However, the chain length should be the same, since we are looking for the shortest sequence of operations.

## Restrictions

The input numbers will be between 0 and 1000000, inclusive. All numbers in the sequence must also be within this range.

## Example

#### Input

*   4284 1131  

#### Output

*   Initial Value: 4284
*   Multiplied 4 and 284
*   Value: 1136
*   Added 3
*   Value: 1139
*   Swapped bits 3 and 4
*   Value: 1131
*   Chain length: 4

## THE Problem

Write the solver described above in any language, and then use it to solve the following problems.

*   53453 24
*   1 999997
*   1337 5555

Your solution should be, for each problem, some text that looks basically like the output you see above in the example - the text doesn't have to be EXACTLY the same as long as all the moves are valid (although of course its nice if it is).

Please DO include the chain length at the end.

There are multiple solutions for some of these problems, but as long as your solution is one of the minimum chain length solutions and is valid, it is correct.

If the problem has no valid solution, simply state the problem has no solution.

Once you have your solution, email it to [internships@zappos.com](mailto:internships@zappos.com)

The winners are the **FIRST CORRECT** answers to **ALL THREE** problems. Your official time of entry is when our email records the email arrival (not responsible for net weather!). Shorter solutions (less steps) are preferred over longer ones in case of a tie.

Please also attach your source code - we'd love to see your approach!

**IF YOU DON'T EMAIL YOUR SOLUTION YOU CANNOT WIN**

## Extra Test Cases

If you want some extra data to test your algorithm, here's a few more known-good sample outputs


#### Input

*   525 163534  

#### Output

*   Initial Value: 525
*   Added 525
*   Value: 1050
*   Added 1050
*   Value: 2100
*   Swapped bits 11 and 12
*   Value: 4148
*   Swapped bits 12 and 13
*   Value: 8244
*   Swapped bits 13 and 14
*   Value: 16436
*   Added 643
*   Value: 17079
*   Swapped bits 14 and 15
*   Value: 33463
*   Swapped bits 15 and 16
*   Value: 66231
*   Swapped bits 16 and 17
*   Value: 131767
*   Added 31767
*   Value: 163534
*   Chain length: 11


#### Input

*   0 1  

#### Output

*   No solution
