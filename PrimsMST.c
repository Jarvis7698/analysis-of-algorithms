#include<stdio.h>
#define INF 9999

int V,E,G[10][10],C[10][10],key[10],pi[10],vst[10];
int i,j,w,u,v,Q,cost=0,sum,fg=0;

void init() {
	for(i=0;i<10;i++) {
		key[i] = INF;
		vst[i] = 0;
		for(j=0;j<10;j++) {
			G[i][j] = 0;
			C[i][j] = 0;
		}
	}
}

int min() {
	int k,m,mindex=1;
	/*FIND MINIMUM KEY NODE*/
	for(k=0;k<V;k++) {
		if(vst[k]==1) continue;
		else {
			m =key[k];
			mindex=k;
			break;
		}
	}
	for(k=0;k<V;k++) {
		if(m>key[k] && vst[k]==0) {
			mindex=k;
			m=key[k];
		}
	}
	return mindex;
}

void main() {

	init();
	/*UNDIRECTED GRAPH DETAILS*/
	printf("\n-----MST USING PRIM'S ALGORITHM-----\n");
	printf("\nVertices: ");
	scanf("%d",&V);
	printf("\nEdges: ");
	scanf("%d",&E);
	
	/*ADJACENCY MATRIX WITH WEIGHT*/
	printf("\nEnter %d Edges: \n",E);
	for(i=0;i<E;i++) {
		printf("\nE%d: ",i+1);
		scanf("%d %d",&u,&v);
		printf("Weight of E%d: ",i+1);
		scanf("%d",&w);
		C[u-1][v-1] = w;
		C[v-1][u-1] = w;
		G[u-1][v-1] = 1;
		G[v-1][u-1] = 1;
	}
	
	/*CHECK FOR ISOLATED NODE*/
	for(i=0;i<V;i++) {
		sum=0;
		for(j=0;j<V;j++) {
			sum+=G[i][j];
		}
		if(sum==0) {
			fg=1;
			printf("\nGraph Error: Isolated Node '%c' Detected!",i+65);
		}
	}	
	if(fg==0) {	
		/*PRIMS ALGORITHM*/
		key[0]= 0;
		pi[0] = 0;Q=V;
		while(Q>0) {
			u = min();
			vst[u] = 1;
			for(v=0;v<V;v++) {
				if(G[u][v]==1) {
					if(vst[v]!=1 && C[u][v]<key[v]) {
						key[v] = C[u][v];
						pi[v] = u;
					}
				}
			}
			Q--;
		}
		/*DISPLAY MST*/
		printf("\nMST Edges:");
		for(i=1;i<V;i++) {
			cost += key[i];
			printf("\n\t%c--[%d]--%c",pi[i]+65,C[pi[i]][i],i+65);
		}
		printf("\n\nTotal Cost: %d\n",cost);
	}
}
