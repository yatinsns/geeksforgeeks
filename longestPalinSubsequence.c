#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int longestPalindromeLength(char* s) {
  int length = strlen(s);
  int **arr = malloc(length * sizeof(int *));
  for (int i = 0; i < length; i++) {
    arr[i] = malloc(length * sizeof(int));
  }

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      arr[i][j] = 0;
    }
  }

  for (int i = 0; i < length; i++) {
    arr[i][i] = 1;
  }

  for (int diff = 1; diff < length; diff++) {
    for (int i = 0; (i + diff) < length; i++) {
      int j = i + diff;

      if (s[i] == s[j]) {
        arr[i][j] = arr[i+1][j-1] + 2;
      } else {
        arr[i][j] = MAX(arr[i][j-1], arr[i+1][j]);
      }
    }
  }

  return arr[0][length-1];
}

int main(int argc, char *argv[]) {
  char *str = "forgeeksskeeg-for";
  int result = longestPalindromeLength(str);
  printf("result : %d", result);

  return 0;
}
