#include <stdio.h>

int main() {
    int n;
    int matrix[100][100];
    int i, j;
    int isIdentity = 1;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j && matrix[i][j] != 1)
                isIdentity = 0;
            if (i != j && matrix[i][j] != 0)
                isIdentity = 0;
        }
    }

    if (isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}