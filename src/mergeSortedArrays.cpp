/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	struct transaction *merg_array = (transaction*)malloc(sizeof(transaction)*(ALen + BLen));
	int in = 0, check, k = 0, i = 0, j = 0;

	if (A == NULL || B == NULL)
		return 0;

	for (i = 0; i < ALen && in<BLen; i++)
	{
		check = 0;
		for (j = 6; j < 10; j++)
		{
			if (A[i].date[j]>B[in].date[j])
			{
				merg_array[k] = B[in];
				check = 1;
				in++;
				i--;
				k++;
				break;
			}
			else
			if (A[i].date[j] < B[in].date[j])
			{
				merg_array[k] = A[i];
				k++;
				check = 1;
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
					merg_array[k] = B[in];
					in++;
					i--;
					k++;
					check = 2;
				}
				else
				if (A[i].date[j] < B[in].date[j])
				{
					merg_array[k] = A[i];
					k++;
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
						merg_array[k] = B[in];
						k++;
						in++;
						i--;
						check = 3;
					}
					else
					if (A[i].date[j] < B[in].date[j])
					{
						merg_array[k] = A[i];
						k++;
						check = 3;
					}
				}
				if (check == 3)
					continue;
				else
				{
					merg_array[k] = B[in];
					merg_array[k + 1] = A[i];
					in++;
					k = k + 2;
				}
			}
		}

	}

	while (i < ALen)
	{
		merg_array[k] = A[i];
		k++;
		i++;
	}

	while (in < BLen)
	{
		merg_array[k] = B[in];
	k++;
	in++;
}
	return merg_array;

}