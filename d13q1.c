#include <stdio.h>

int main() {
    int r, c;
    int matrix[100][100];
    int top, bottom, left, right;
    int i;

    scanf("%d %d", &r, &c);

    for (i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    top = 0;
    bottom = r - 1;
    left = 0;
    right = c - 1;

    while (top <= bottom && left <= right) {

        for (i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        for (i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        if (top <= bottom) {
            for (i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        if (left <= right) {
            for (i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }

    return 0;
}