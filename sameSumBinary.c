#include <stdio.h>
#include <stdlib.h>

void update_max_length_if_required(int *max_length, int new_value) {
  printf("Updating max_length with value : %d", new_value);
  if (*max_length < new_value) {
    *max_length = new_value;
  }
}

int length_longest_common_span(int *arr1, int *arr2, int n) {
  int number_of_diffs = (2 * n) + 1;
  int *diff_info = (int *)malloc(number_of_diffs * sizeof(int));
  for (int i = 0; i < number_of_diffs; i++) {
    diff_info[i]= -1;
  }

  int max_length = 0;
  int prefix_sum_arr1 = 0;
  int prefix_sum_arr2 = 0;
  for (int i = 0; i < n; i++) {
    prefix_sum_arr1 += arr1[i];
    prefix_sum_arr2 += arr2[i];

    int diff = prefix_sum_arr1 - prefix_sum_arr2;
    printf("prefix %d %d\n", prefix_sum_arr1, prefix_sum_arr2);
    printf("diff : %d\n", diff);

    if (diff == 0) {
      update_max_length_if_required(&max_length, i + 1);  
    } else {
      int index = diff + n;
      if (diff_info[index] == -1) {
        diff_info[index] = i;
      } else {
        update_max_length_if_required(&max_length, i - diff_info[index]);
      }
    }
    printf("max_length : %d\n\n", max_length);
  }
  return max_length;  
}

int main(int argc, char *argv[]) {
  const int length = 6;
  int arr1[] = {0, 1, 0, 0, 0, 0};
  int arr2[] = {1, 0, 1, 0, 0, 1};

  int result = length_longest_common_span(arr1, arr2, length);
  printf("result: %d", result);

  return 0;
}
