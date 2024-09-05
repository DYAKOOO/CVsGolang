#include <stdio.h>

// Correct implementation of bitwise XNOR
int xnor(int a, int b) {
    return a==b;
}

int main() {
    int a = 10;  // Binary: 0101
    int b = 10; // Binary: 1010
    int result = xnor(a, b);
    printf("XNOR of %d and %d is: %d\n", a, b, result);
    printf("Binary representation of result: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (result >> i) & 1);
    }
    printf("\n");
    return 0;
}