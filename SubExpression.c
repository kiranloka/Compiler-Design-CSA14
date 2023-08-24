#include <stdio.h>

int main() {
    int a = 5, b = 3, c = 2;
    int result1, result2, result3;

    // Original expressions
    result1 = a + b * c;
    result2 = a + b * c;
    result3 = b * c - a;

    // Optimized expressions
    int temp = b * c;
    result1 = a + temp;
    result2 = a + temp;
    result3 = temp - a;

    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);
    printf("Result 3: %d\n", result3);

    return 0;
}
