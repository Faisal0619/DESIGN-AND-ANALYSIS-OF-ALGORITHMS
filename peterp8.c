#include <stdio.h>

int calculate_points(int sequence[], int n) {
  // Create a frequency table to store the count of each number in the sequence.
  int freq[1001] = {0};
  int num,i; // Assuming the maximum value in the sequence is 1000
  for (i = 0; i < n; i++) {
    freq[sequence[i]]++;
  }

  // Initialize the maximum points to 0.
  int max_points = 0;

  // Iterate through each number in the sequence.
  for (num = 0; num <= 1000; num++) {
    // Calculate the potential points for the current number.
    int potential_points = freq[num] + freq[num + 1] + freq[num - 1];

    // Update the maximum points if necessary.
    max_points = fmax(max_points, potential_points);
  }

  return max_points;
}

int main() {
  int n;
  printf("Enter the number of elements in the sequence: ");
  scanf("%d", &n);
int i;
  int sequence[n];
  printf("Enter the sequence elements:\n");
  for ( i = 0; i < n; i++) {
    scanf("%d", &sequence[i]);
  }

  int max_points = calculate_points(sequence, n);
  printf("Maximum points Peter can get: %d\n", max_points);

  return 0;
}
