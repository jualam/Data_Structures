#include <stdio.h>

// Recursive Fibonacci function definition
int fib(int n) {
    if (n == 1 || n == 2)
        return 1; // Base case: return 1 for the first two positions
    else
        return fib(n-1) + fib(n-2); // Recursive case: sum of the two preceding numbers
}

int main() {
    int n = 5; // Example: finding the 5th Fibonacci number
    printf("Fibonacci number at position %d is %d\n", n, fib(n));
    return 0;
}
