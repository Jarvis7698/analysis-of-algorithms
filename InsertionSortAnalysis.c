/*
**Insertion Sorting Analysis
*/

#include<stdio.h>
#define size 10

int a[size],i,j,shift=0,comp=0,total=0,num=size;

void main() {
	
	printf("\nEnter Array: \n");
	for(i=0;i<size;i++) {
		scanf("%d",&a[i]);
	}
	total=num*(num-1)/2;
	
	/*Insertion Sorting Algorithm*/
	for(i=1;i<size;i++) {
		int temp=a[i];
		j=i-1;
		if(a[j]>temp && j>=0) {
			while(a[j]>temp && j>=0) {
				a[j+1]=a[j];
				j--;
				comp++;
				shift++;
			}
			a[j+1]=temp;
		}
		else comp++;
	}
	
	printf("\nSorted Array: \n");
	for(i=0;i<size;i++) {
		printf("%d ",i+1,a[i]);
	}
	
	printf("\n\nShifting: %d\nComparison: %d",shift,comp);
	printf("\nPercentage Of Shift: %.2f",(float)(shift*100/total));
	printf("\nPercentage Of Comparison: %.2f",(float)(comp*100/total));
	float avg = (float)(comp+shift)*100/(total*2);
	printf("\nAverage Percentage: %.2f\n",avg);
	if(avg<=33.0) {
		printf("\nBest Case\n");
	} else if(avg<=67.0) {
		printf("\nAverage Case\n");
	} else {
		printf("\nWorst Case\n");
	}
}

