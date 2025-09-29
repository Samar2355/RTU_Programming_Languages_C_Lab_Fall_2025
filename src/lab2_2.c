#include <stdio.h>

/*
    Task:
    Write a function `long long factorial(int n)` that computes n!
    using a loop (not recursion).

    In main():
      - Ask user for an integer n
      - If n is negative, print an error and exit
      - Otherwise, call factorial and print the result
*/

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
    // TODO: compute factorial iteratively // placeholder

int main(void) {
    int n;

    printf("Enter a non-negative integer n: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Ērror") ;
        return 1;
    }
     else {
        long long result = factorial(n);
        printf("Factorial of %d is %lld\n", n, result);
    }

    return 0;


    // TODO: validate input, call function, print result

    return 0;
}
