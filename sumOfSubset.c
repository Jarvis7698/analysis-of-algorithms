/*
**	Sum Of Subsets Problem
*/

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

int inc[10],wsf[10],sum,n;

int promising(int i, int wt, int tot) {
	return ( ((wt+tot)>=sum) && ((wt==sum) || ((wt+wsf[i+1])<=sum)) );
}

void sumofsubsets(int i, int wt, int tot) {
	int j;
	if(promising(i, wt, tot)) {
		if(wt == sum) {
			printf("\n{");
			for(j=0; j<=i; j++) {
				if(inc[j])
					printf("%d,",wsf[j]);		
			}
			printf("\b}");
			return;
		}
		else {
			inc[i+1] = TRUE;
			sumofsubsets(i+1, wt+wsf[i+1], tot-wsf[i-1]);
			inc[i+1] = FALSE;
			sumofsubsets(i+1, wt, tot-wsf[i-1]);		
		}
	}
}

int main() {
	int i,j,temp,total=0;

	printf("\nNumber Of Integers: ");
	scanf("%d",&n);

	printf("\nEnter %d Integers: ",n);
	for(i=0; i<n; i++) {
		scanf("%d", &wsf[i]);
		total += wsf[i];
		inc[i]=0;
	}
		
	printf("\nSum To Create: ");
	scanf("%d", &sum);

	if(sum > total) {
		printf("\nSum Not Possible!!\n");	
	} else {
		printf("\nPossible Solutions:");
		sumofsubsets(-1, 0, total);
		printf("\n");
	}
	system("pause");
	return 0;
}

