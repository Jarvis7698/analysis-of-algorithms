/*
** Longest Common Subsequence(LCS) - Dynamic Programming.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct lcs{
	int mag; /* MAGNITUDE */ 
	int dir; /* DIRECTION: Up=1,L.Side=2,Diag=3 */
}tab[20][20];

char stg1[20],stg2[20],LCS[20];
int len1,len2,i,j,p=-1;

/*RECORD LCS CHARACTERS*/
void putinLCS(char ch) {
	p++;
	LCS[p]=ch;
	LCS[p+1]='\0';
}

int main() {
	printf("\n----------LCS----------\n");
	
	/*FIRST STRING*/
	printf("\n First String: ");
	gets(stg1);
	len1=strlen(stg1);
	
	/*SECOND STRING*/
	printf("\nSecond String: ");
	gets(stg2);
	len2=strlen(stg2);
	
	/*FIRST ROW & FIRST COLUMN ZERO*/
	for(i=0,j=0;i<=len1+1,j<=len2+1;i++,j++) {
		tab[0][i].mag=0;tab[0][i].dir=0;
		tab[j][0].mag=0;tab[j][0].dir=0;
	}
	
	/*MEMOIZATION TABLE*/
	for(i=1;i<=len1;i++) {
		for(j=1;j<=len2;j++) {
			if(stg1[i-1]==stg2[j-1]) {
				/*CHARACTERS ARE SAME*/
				tab[i][j].mag = 1+tab[i-1][j-1].mag;
				tab[i][j].dir = 3; /* DIAGONAL-ARROW */
			}
			else {
				/*CHARACTERS ARE NOT SAME*/
				if(tab[i-1][j].mag==tab[i][j-1].mag || tab[i-1][j].mag>tab[i][j-1].mag) {
					/*DIAGONALS ARE SAME OR UPPER VALUE IS GREATER*/
					tab[i][j].mag = tab[i-1][j].mag;
					tab[i][j].dir = 1; /*UP-ARROW*/
				}
				else {
					/*TAKE VALUE FROM LEFT*/
					tab[i][j].mag = tab[i][j-1].mag;
					tab[i][j].dir = 2; /*L.SIDE-ARROW*/
				}
			}
		}
	}
	printf("\nMEMOIZATION TABLE: \n\n");
	for(j=0;j<len2;j++) printf("%6c",stg2[j]);
	for(i=1;i<=len1;i++) {
		printf("\n\n %c",stg1[i-1]);
		for(j=1;j<=len2;j++) {
			printf("%3d",tab[i][j].mag);
			if(tab[i][j].dir==1) printf("[^]");
			if(tab[i][j].dir==2) printf("[<]");
			if(tab[i][j].dir==3) printf("[\\]");
		}
	}
	
	/*BACKTRACKING ALGORITHM*/
	i=len1;
	j=len2;
	while(i>=0 && j>=0) {
		if(tab[i][j].dir == 3) {
			/*MARK & MOVE DIAGONALLY*/
			putinLCS(stg1[i-1]);
			i-=1;
			j-=1;
		}
		else if(tab[i][j].dir == 2) {
			/*MOVE LEFT*/
			j-=1;
		}
		else {
			/*MOVE UPWARD*/
			i-=1;
		}
	}
	
	/*LCS FOUND*/
	strrev(LCS);
	printf("\n\n\nLongest Common Subsequence: %s\n",LCS);
	
	system("pause");
	return 0;
}

