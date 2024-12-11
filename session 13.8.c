#include <stdio.h>

int findGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    printf("Nh?p s? nguy�n th? nh?t: ");
    scanf("%d", &num1);

    printf("Nh?p s? nguy�n th? hai: ");
    scanf("%d", &num2);

    int gcd = findGCD(num1, num2);

    printf("U?c chung l?n nh?t c?a %d v� %d l�: %d\n", num1, num2, gcd);

    return 0;
}
