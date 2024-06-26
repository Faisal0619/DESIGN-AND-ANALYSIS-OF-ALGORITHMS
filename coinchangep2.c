#include <stdio.h>
#include <limits.h>
int min_coins(int amount) {
  // Create a table to store the minimum number of coins required for each amount
  int dp[amount + 1];
  int coin[]={1 ,3 ,4};
int i,j;
  // Initialize the table: 0 coins needed for amount 0
  dp[0] = 0;

  // Initialize the rest of the table with infinity (representing an unreachable state)
  for (i = 1; i <= amount; i++) {
    dp[i] = INT_MAX;
  }

  // Iterate through all possible amounts and denominations
  for ( i = 1; i <= amount; i++) {
    // Check for denominations 1, 3, and 4
    for (j=0;j<2;j++ ) {
      // If the current coin is less than or equal to the amount
      if (i >= coin[j]) {
        // Update the table value if using the current coin leads to a smaller number of coins
        dp[i] = fmin(dp[i], dp[i - coin[j]] + 1);
      }
    }
  }

  // Check if it's impossible to make change
  return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
  int amount;
  printf("Enter the amount (in cents): ");
  scanf("%d", &amount);

  int min_coins_needed = min_coins(amount);

  if (min_coins_needed != -1) {
    printf("Minimum number of coins needed for %d cents: %d\n", amount, min_coins_needed);
  } else {
    printf("It's impossible to make change for %d cents using denominations 1, 3, and 4.\n", amount);
  }

  return 0;
}
