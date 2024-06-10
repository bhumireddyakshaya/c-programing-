#include <stdio.h>

int main() {
    int arr[] = {10, 5, 8, 3, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int smallest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    printf("The smallest element in the array is: %d", smallest);

    return 0;
}

