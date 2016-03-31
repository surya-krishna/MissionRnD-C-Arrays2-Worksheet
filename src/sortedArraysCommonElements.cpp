/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include <iostream>


struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	int in = 0, check, k = 0, i = 0, j = 0;
	struct transaction *same_trans = (transaction *)malloc(sizeof(transaction)*ALen);

	if (A == NULL||B==NULL)
		return 0;
	
	for (i = 0; i < ALen; i++)
	{
		check = 0;
		for (j = 6; j < 10; j++)
		{
			if (A[i].date[j]>B[in].date[j])
			{
				check = 1;
				in++;
				i--;
				break;
			}
			else
			if (A[i].date[j] < B[in].date[j])
			{
				check=1;
			}
		}
		if (check == 1)
		{
			continue;
		}
		else
		{
			for (j = 3; j < 5; j++)
			{
				if (A[i].date[j]>B[in].date[j])
				{
					in++;
					i--;
					check = 2;
				}
				else
				if (A[i].date[j] < B[in].date[j])
				{
					check = 2;
				}
			}
			if (check == 2)
				continue;
			else
			{
				for (j = 3; j < 5; j++)
				{
					if (A[i].date[j]>B[in].date[j])
					{
						in++;
						i--;
						check = 3;
					}
					else
					if (A[i].date[j] < B[in].date[j])
					{
						check = 3;
					}
				}
				if (check == 3)
					continue;
				else
				{
					same_trans[k] = A[i];
					k++;
				}
			}
		}
	
	}
	if (k == 0)
		return 0;
	return same_trans;
}