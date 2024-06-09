#include <stdio.h>

int main() {
    int array[100] = {1, 2, 3, 4, 5};
    int n = 5; 
    int position = 2; 
    int data = 10; 

    for (int i = n; i >= position; i--) {
        array[i] = array[i - 1];
    }

    array[position - 1] = data;
    n++; 

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

