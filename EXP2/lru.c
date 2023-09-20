#include<stdio.h>

int findLRU(int t[], int n) {
    int i, min = t[0], p = 0;
    for (i = 1; i < n; i++) { 
        if (t[i] < min) {
            min = t[i];
            p = i;
        }
    }
    return p;
}

int main() {
    int np, p[50], f[50], nf, pf = 0, f1, f2, t[50], c = 0, pos;
    printf("Enter number of pages: ");
    scanf("%d", &np);
    printf("Enter the page numbers\n");
    for (int i = 1; i <= np; i++) {
        scanf("%d", &p[i]);
    }
    printf("Enter no of frames: ");
    scanf("%d", &nf);
    for (int i = 0; i < nf; i++) {
        f[i] = -1;
    }

    printf("Ref String\t Page frames\n");
    for (int i = 1; i <= np; i++) {
        printf("%d\t", p[i]);
        f1 = 0;
        f2 = 0;
        for (int j = 0; j < nf; j++) {
            if (f[j] == p[i]) {
                c++;
                t[j] = c;
                f1 = 1;
                f2 = 1;
                break;
            }
        }
        if (f1 == 0) {
            for (int j = 0; j < nf; j++) {
                if (f[j] == -1) {
                    c++;
                    pf++;
                    f[j] = p[i];
                    t[j] = c;
                    f2 = 1;
                    break;
                }
            }
        }
        if (f2 == 0) {
            pos = findLRU(t, nf);
            c++;
            pf++;
            f[pos] = p[i];
            t[pos] = c;
        }
        for (int j = 0; j < nf; j++) {
            printf("%d\t", f[j]);
        }
        printf("\n");
    }
    printf("No of faults = %d\n", pf);
}

