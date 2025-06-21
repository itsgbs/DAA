#include<stdio.h>

int G[20][20], x[20] = {0}, c = 0;
int n, m; // m = number of colors

void printgcoloured(int n) {
	int i;
    for (i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void nextvalue(int k) {
    while (1) {
        x[k] = (x[k] + 1) % (m + 1); // colors from 1 to m
        if (x[k] == 0)
            return; // all colors tried, backtrack

        int i;
        for (i = 1; i < k; i++) {
            if (G[i][k] == 1 && x[i] == x[k])
                break;
        }
        if (i == k)
            return; // no conflict
    }
}

void mcoloring(int k) {
    while (1) {
        nextvalue(k);
        if (x[k] == 0)
            return;

        if (k == n) {
            c++;
            printgcoloured(n);
        } else {
            mcoloring(k + 1);
        }
    }
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    m = n - 2;

    printf("The SOLUTION VECTORS are:\n");
    mcoloring(1);

    printf("The Total number of SOLUTIONS: %d\n", c);
    return 0;
}
/*
0 1 1 1 0
1 0 1 1 0
1 1 0 0 1
1 1 0 0 1
0 0 1 1 0
*/