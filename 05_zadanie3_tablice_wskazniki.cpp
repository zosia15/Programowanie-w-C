#include <cstdio>

#define SIZE 10

int main() {
    int numbers[SIZE] = {1, 2, 3, -4, 50, 6, 7, 8, 9, 10};

    printf("Arrays\n");

    for (int i = 0; i < SIZE; i++) {
        printf("*(numbers + %d) = %d\n", i, *(numbers + i));
    }

    int max = *numbers;

    for (int i = 0; i < SIZE; i++) {
        if (*(numbers + i) > max) {
            max = *(numbers + i);
        }
    }

    printf("max = %d\n", max);

    int sum = 0;

    for (int i = 0; i < SIZE; i++) {
        sum += *(numbers + i);
    }

    printf("sum = %d\n", sum);

    float average = (float)sum / SIZE;

    printf("average = %.2f\n", average);

    return 0;
}