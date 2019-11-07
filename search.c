#include <stdio.h>
#include <stdlib.h>


int search(int *a, int key);
int main()
{
	int a[7] = {2, 4, 6, 9, 23, 50, 80};
	int i;
	if((i = search(a, 9)) != -1)
	{
		printf("find it %d\n", i);
	}

	return 0;
}

int search(int *a, int key)
{
	int low,high,mid;
	low = 0;
	high = 6;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(key == a[mid])
			return mid;
		else if(key > a[mid])
			low = mid + 1;
		else if(key < a[mid])
			high = mid - 1;
	}
	return -1;
}

