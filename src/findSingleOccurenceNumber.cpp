/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#include<iostream>
void merge(int *A,int min,int mid,int max)
{
	int temp[100];
	int i, j, m,k;
	j = min;
	m = mid + 1;
	for (i = min; j <= mid&&m <= max; i++)
	{
		if (A[j] <= A[m])
		{
			temp[i] = A[j];
			j++;
		}
		else
		{
			temp[i] = A[m];
			m++;
		}
	}
	if (j > mid)
	{
		for (k = m; k <= max; k++)
		{
			temp[i] = A[k];
			i++;
		}
	}
	else
	{
		for (k = j; k <= mid; k++)
		{
			temp[i] = A[k];
			i++;
		}
	}
	for (k = min; k <= max; k++)
	{
		A[k] = temp[k];
	}
}



void part(int *A, int min,int max)
{
	int mid;
	if (min < max)
	{

		mid = (min + max) / 2;
		part(A, min, mid);
		part(A, mid + 1, max);
		merge(A, min, mid, max);
	}
}


int findSingleOccurenceNumber(int *A, int len) {
	
	int i;


	if (A ==NULL)
		return -1;
	
	part(A,0,len-1);
	
	if (A[0] != A[1])
		return A[0];
	if (A[len - 1] != A[len - 2])
		return A[len-1];
	for (i = 0; i < len; i++)
	{

		if (A[i - 1] != A[i] && A[i] != A[i + 1])
			return A[i];
	}
	return 0;
}