#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_search.h"

int main()
{
  int my_data[ARRAY_SIZE];
  printf("What number are you looking for?\n");
  int target;
  scanf("%d", &target); 
  printf("\n");

  FILE* fptr = fopen("search_data.csv", "r");

  if(fptr == NULL)
  {
    printf("Error opening the file!");
    return -1;
  }
 
  int i = 0;
  char buffer[1024];
  int value;
  while((fgets(buffer, 1024, fptr)) && (i <= ARRAY_SIZE))
  {
    char* unparsed_value = strtok(buffer, ", ");
    
    while(unparsed_value)
    {
      value = atoi(unparsed_value);
      my_data[i] = value;
      ++i;
      unparsed_value = strtok(NULL, ", ");
    }
  }

  binary_search(target, my_data);

  fclose(fptr);

  return 0;
}

