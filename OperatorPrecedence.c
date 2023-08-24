#include <stdio.h>

int main() {
    int a = 5, b = 10, c = 15;
    int result;

    result = a + b * c;
    printf("a + b * c = %d\n", result);

    result = (a + b) * c;
    printf("(a + b) * c = %d\n", result);

    result = a / b + c;
    printf("a / b + c = %d\n", result);

    result = a + b / c;
    printf("a + b / c = %d\n", result);

    result = a > b && b < c;
    printf("a > b && b < c = %d\n", result);

    result = a > b || b < c;
    printf("a > b || b < c = %d\n", result);

    result = !a;
    printf("!a = %d\n", result);

    return 0;
}

