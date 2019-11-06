/*
**	0-1 Knapsack Algorithm - Dynamic Programming
*/

#include<stdio.h>
#include<stdlib.h>

struct object {
	int p;
	int w;
} item[10];

int W,i,k,n,w,maxp=0,B[10][100],marked[10];

int main() {

	/* PROBLEM DATA */
	printf("\nCapacity Of Knapsack: ");scanf("%d",&W);
	printf("\nNumber Of Items: ");scanf("%d",&n);
	
	for(i=0;i<n;i++) {
		printf("\n[Item %c] Profit & Weight: ",i+65);
		scanf("%d %d",&item[i+1].p,&item[i+1].w);
		marked[i]=0;
	}
	
	for(w=0;w<=W;w++) B[0][w]=0;
	for(i=0;i<=n;i++) B[i][0]=0;
	
	/* MEMOISING TABLE */
	for(i=1;i<=n;i++) {
		for(w=0;w<=W;w++) {
			if(item[i].w <= w) { 
				/*Item Can Be A Part Of Solution*/
				if((item[i].p + B[i-1][w-item[i].w])>B[i-1][w]) {
					B[i][w] = item[i].p + B[i-1][w-item[i].w];
				}
				else {
					B[i][w] = B[i-1][w];
				}
			}
			else { 
				/*item[i].w > w 
					thus item cannot be a part of solution*/
				B[i][w] = B[i-1][w];
			}
		}
	}
	
	printf("\nDynamic Programming: Memoization Table\n\ni/W");
	for(i=0;i<=W;i++) printf("%3d",i);
	for(i=0;i<=n;i++) {
		printf("\n%3d",i);
		for(w=0;w<=W;w++) {
			printf("%3d",B[i][w]);
		}
	}
	
	/* PICKING ITEMS */
	i=n;
	k=W;
	while(i>=0 && k>=0) {
		if(B[i][k] != B[i-1][k]) {
			marked[i-1]=1;
			maxp+=item[i].p;
			k-=item[i].w;
		}
		i-=1;
	}
	printf("\n\nMaxProfit: %d\n",maxp);
	printf("\nItems Picked: ");
	for(i=0;i<=n;i++) {
		if(marked[i]==1) 
			printf("%c ",i+65);
	}
	printf("\n");
	
	system("pause");
	return 0;
}
