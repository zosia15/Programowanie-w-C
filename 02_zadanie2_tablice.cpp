#include <cstdio>

#define SIZE 10

int main() {
    int numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Arrays\n");

    for (int i = 0; i < SIZE; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    int max = numbers[0];
    for (int i = 1; i < SIZE; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    printf("max = %d\n", max);

    int min = numbers[0];
    for (int i = 1; i < SIZE; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    printf("min = %d\n", min);

    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += numbers[i];
    }

    printf("sum = %d\n", sum);

    float average = (float)sum / SIZE;
    printf("average = %.2f\n", average);

    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] == min) {
            numbers[i] = max;
        } else if (numbers[i] == max) {
            numbers[i] = min;
        }
    }

    printf("\nAfter swap:\n");

    for (int i = 0; i < SIZE; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    return 0;
}