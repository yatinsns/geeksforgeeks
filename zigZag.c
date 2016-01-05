#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *zig_zag(char *str, int number_of_rows) {
  if (number_of_rows == 1) {
    return str;
  }

  int length = strlen(str);

  char **rows = (char **)malloc(number_of_rows * sizeof(char*));
  int row_length = (length / 3) + 2;
  for (int i = 0; i < number_of_rows; i++) {
    rows[i] = (char *)malloc(row_length * sizeof(char));
    rows[i][0] = '\0';
  } 
  
  char *ptr = str;
  int direction = 0;
  int row = 0;
  while(*ptr != '\0') {
    int current_length = strlen(rows[row]); 
    rows[row][current_length] = *ptr;
    rows[row][current_length + 1] = '\0';
    if (direction == 0) {
      if (row == number_of_rows - 1) {
        row = row - 1;
        direction = 1;
      } else {
        row++;
      }
    } else {
      if (row == 0) {
        row = row + 1;
        direction = 0;
      } else {
        row--;
      }
    }
    ptr++;
  }

  char *result = (char *)malloc((length + 1) * sizeof(char));
  strcpy(result, rows[0]);
  for (int i = 1; i < number_of_rows; i++) {
    strcat(result, rows[i]);
  }
  return result;
}

int main(int argc, char *argv[]) {
  char *input = "GEEKSFORGEEKS";
  int n = 3;

  char *result = zig_zag(input, n);
  printf("result is: %s", result);

  return 0;
}
