##Problem Description:
You are tasked with creating a program that efficiently determines the minimum number of coins needed to make change for a given amount of money. The available coin denominations are 10, 5, and 1. The goal is to provide the optimal change by using the fewest coins possible.

##Program Logic:
The program get_change takes an integer money as input, representing the amount of money for which you need to make change. It employs a greedy algorithm to determine the minimum number of coins needed, considering the available coin denominations.

The program initializes a counter for the total number of coins and an array (coinArr) to store the denominations of the coins used. It iteratively subtracts the largest available denomination (starting from 10 and moving down to 5 and 1) from the remaining money until the entire amount is accounted for.

The result is displayed in the form of an array, indicating the specific denominations of coins used to make change for the given amount. The function then returns the total number of coins used.