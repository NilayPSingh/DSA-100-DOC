#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int arr[100];
    int i, j;
    int minSum;
    int a, b;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    minSum = abs(arr[0] + arr[1]);
    a = arr[0];
    b = arr[1];

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (abs(arr[i] + arr[j]) < minSum) {
                minSum = abs(arr[i] + arr[j]);
                a = arr[i];
                b = arr[j];
            }
        }
    }

    printf("%d %d", a, b);

    return 0;
}