#include <stdio.h>

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    float average;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    average = (float)sum / n;

    printf("The average of the array is: %.2f", average);

    return 0;
}

