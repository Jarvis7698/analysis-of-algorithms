/*
** N-Queen Problem - BACKTRACKING
*/

#include<stdio.h>
#include<stdlib.h>

int x[10],n,c=0;

int place(int k, int i) {
	int j;
	for(j=1; j<k; j++) {
		if(x[j]==i || abs(x[j]-i) == abs(j-k))
			return 0;
	}
	return 1;
}

void write(int c) {
	int i;
	printf("\nSolution [%2d]: [ ", c+1);
	for(i=1; i<=n; i++)
		printf("%d ", x[i]);
	printf("]\n");
}

void queen(int k, int n) {
	int i;
	for(i=1; i<=n; i++) {
		if(place(k, i)) {
			x[k] = i;
			if(k == n) {
				write(c);
				c++;
			}
			else queen(k+1, n);
		}
	}
}

int main() {
	int i;
	printf("\nN-Queen Problem\n");
	printf("\nQueens: ");
	scanf("%d", &n);
	
	for(i=0;i<=n;i++) x[i]=0;
	queen(1,n);
	
	system("pause");
	return 0;
}
