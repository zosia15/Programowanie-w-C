#include <cstdio>

#define SIZE 10

void printArray(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
}

int findMaximum(int numbers[], int size) {
    int max = numbers[0];

    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    return max;
}

int calculateSum(int numbers[], int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }

    return sum;
}

float calculateAverage(int numbers[], int size) {
    int sum = calculateSum(numbers, size);
    return (float)sum / size;
}

int main() {
    int numbers[SIZE] = {1, 2, 3, -4, 50, 6, 7, 8, 9, 10};

    printf("Arrays\n");

    printArray(numbers, SIZE);

    printf("Max number: %d\n", findMaximum(numbers, SIZE));

    printf("Average = %.2f\n", calculateAverage(numbers, SIZE));

    return 0;
}