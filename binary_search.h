#include <stdio.h>

#define ARRAY_SIZE 101

int binary_search(int target, int search_array[ARRAY_SIZE])
{
	int min, middle, max;

	min = 0;
	max = ARRAY_SIZE - 1;

	while(min <= max)
	{
		middle = (min + max) / 2;

		if(search_array[middle] == target)
		{
      printf("Number found %d!\n", search_array[middle]);
			return search_array[middle];
		}
		if(search_array[middle] > target)
		{
			printf("The number is bigger than the target: %d.\n", search_array[middle]);
			max = middle - 1;
      continue;
		}
		if(search_array[middle] < target)
		{
			printf("The number is smaller than the target: %d.\n", search_array[middle]);
			min = middle + 1;
		  continue;
    }
  }

	printf("Number not found.\n");
  return -1;
}

