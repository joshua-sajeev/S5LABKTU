#include <stdio.h>

int main() {
	int j, avail, pf = 0, np, nf, p[50], f[50];

	printf("Enter number of pages: ");
	scanf("%d", &np);

	printf("Enter the pages\n");
	for (int i = 1; i <= np; i++) {
		scanf("%d", &p[i]);
	}

	printf("Enter no of frames:");
	scanf("%d", &nf);

	for (int i = 0; i < nf; i++) {
		f[i] = -1;
	}

	j = 0;

	for (int i = 1; i <= np; i++) {
		printf("%d\t",p[i]);
		avail = 0;
		for (int k = 0; k < nf; k++) {
			if (f[k] == p[i]) {
				avail = 1;
				break; 
			}
		}
		if (avail == 0) {
			f[j] = p[i];
			j = (j + 1) % nf;
			pf++;
		}
		for (int k = 0; k < nf; k++) {
			printf("%d\t", f[k]);
		}
		printf("\n");
	}

	printf("Number of page faults = %d", pf);
	return 0;
}

