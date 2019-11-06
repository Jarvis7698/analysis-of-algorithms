/*
** Knuth-Morris-Prath String Pattern Matching Algorithm
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char T[100],P[20];
int pi[20],q,m,n,k,i;

void Compute_Prefix() {
	k = -1;
	pi[0] = k;
	for(q=1; q<m; q++) {
		while( k > -1 && P[k+1] != P[q])
			k = pi[k];
		if(P[k+1] == P[q]) 
			k++;
		pi[q] = k;
	}
}

int main() {
	printf("\nEnter Text: ");
	gets(T);n = strlen(T);
	printf("\nEnter Pattern: ");
	gets(P);m = strlen(P);
	
	Compute_Prefix();
	
	q = -1;
	for(i=0; i<n; i++) {
		while(q > -1 && P[q+1] != T[i])
			q = pi[q];
		if(P[q+1] == T[i])
			q++;
		if(q == m-1) {
			printf("\nPattern Occurs At Shift of %d\n", i-q+1);
		}
	}
	system("pause");
	return 0;
}

