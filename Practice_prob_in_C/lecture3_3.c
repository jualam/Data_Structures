#include <stdio.h>

int fib(int n) {
    if (n <= 0) {
        printf("Error: n must be a positive integer.\n");
        return -1; // Indicate an error condition
    }

    if (n == 1 || n == 2) {
        return 1; // Base cases: the first and second Fibonacci numbers are 1
    }

    int oneBefore = 1; // Represents Fib(n-1)
    int twoBefore = 1; // Represents Fib(n-2)
    int current = 1;   // Initialize current as 1, for the case when n is 1 or 2
    
    for (int i = 3; i <= n; i++) {
        current = oneBefore + twoBefore; // Calculate the current Fibonacci number
        twoBefore = oneBefore; // Update Fib(n-2) to Fib(n-1) for the next iteration
        oneBefore = current;   // Update Fib(n-1) to Fib(n) for the next iteration
    }
    return current;
}

int main() {
    int n = 5; // Example
    int result = fib(n);

    if (result != -1) { // Check if fib function returned an error
        printf("Fibonacci number at position %d is %d\n", n, result);
    }
    
    return 0;
}
