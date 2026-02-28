#include <stdio.h>

int main() {
    int m, n;
    int matrix[100][100];
    int i, j;
    int sum = 0;

    scanf("%d %d", &m, &n);

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < m && i < n; i++) {
        sum = sum + matrix[i][i];
    }

    printf("%d", sum);

    return 0;
}