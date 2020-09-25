#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INF 99999

void printSolution(int tam, int dist[][tam]);
void DFS(int tam, int matrix[][tam],int visited[], int i);

int knowlength(int number){
	int counter=0;
	 while(number != 0){
        number /= 10;
        ++counter;
    }
	return counter;
}

void adjacencyMatrix(int *matrix,int tam,int length){
	printf("%*c ", length+2,' ');
	for(int i=0;i<tam;i++)
		printf("%*d",length+1,i);
	printf("\n");
	printf("%*c ", length+2,'+');
	for(int i=0;i<tam;i++)
		printf("%*s",length+1,"--" );
	printf("\n");
	for(int i=0;i<tam;i++){
		printf("%*d | ",length,i);
		for(int j=0;j<tam;j++)
			printf(" %*d",length,*(matrix+i*tam+j));
		printf("\n");
	}
}

void printEdgelist(int *matrix, int tam, int length){
	int k=0;
	printf("\n");
	for(int i=0;i<tam;i++)
		for(int j=0;j<tam;j++)
			if(*(matrix+i*tam+j) != -1){
				printf("Edge %2d connects node %2d with node %2d with a weight: %d\n",k,i,j, *(matrix+i*tam+j));
				k++;
			}
}

void printAdjacencylist(int *matrix, int tam, int length){
	int k=0;
	printf("\n");
	for(int i=0;i<tam;i++)
		for(int j=0;j<tam;j++)
			if(*(matrix+i*tam+j) != -1){
				printf("Node %d connects with node %d (weight: %*d)\n",i,j,length,*(matrix+i*tam+j));
				k++;
			}	
}

void printBFS(int tam, int matrix[][tam]){
	int queue[tam],k1=1,k2=0,tmp=0, posicion=1;
	queue[0] = 0;
	for(int i=0;i<tam;i++){
		if(matrix[0][i]!=-1){
			queue[k1]=i;
			k1++;
		}
	}
	printf("%d: Root: Node 0\n",posicion);
	posicion++;
	do{
		tmp = queue[k2];
		for(int i=0;i<tam;i++){
			if(matrix[tmp][i]!=-1){
				printf("%d: Node: %d -> %d \n",posicion,tmp,i);
				posicion++;

				int centinel=0;
				for(int j=0;j<tam;j++){
					if(i == queue[j])
						centinel++;
				}
				if(centinel == 0){
					queue[k1]=i;
					k1++;
				}
			}
		}
		k2++;
	}while(k2!=tam);
}

void pruebaDFS(int tam, int matrix[][tam],int visited[]){
	int i,j;
	for(i=0;i<tam;i++)
        visited[i]=0;
    DFS(tam,matrix,visited,0);
}
 
void DFS(int tam, int matrix[][tam],int visited[], int i){
    int j;
    printf("\n%d",i);
    visited[i]=1;
    
    for(j=0;j<tam;j++)
       if(!visited[j]&&matrix[i][j]!=-1)
            DFS(tam,matrix,visited,j);
}

void floydWarshall (int tam,int graph[][tam]){ 
	/* dist[][] will be the output matrix that will finally have the shortest 
	distances between every pair of vertices */
	int dist[tam][tam], i, j, k; 

	/* Initialize the solution matrix same as input graph matrix. Or 
	we can say the initial values of shortest distances are based 
	on shortest paths considering no intermediate vertex. */
	for (i = 0; i < tam; i++) 
		for (j = 0; j < tam; j++)
			if(i==j)
				dist[i][j] = 0;
			else if(graph[i][j]== -1 && i!=j)
				dist[i][j]=INF;
			else
				dist[i][j] = graph[i][j]; 

	for(k = 0; k < tam; k++){ 
		// Pick all vertices as source one by one 
		for(i = 0; i < tam; i++){ 
			// Pick all vertices as destination for the 
			// above picked source 
			for(j = 0; j < tam; j++){
				// If vertex k is on the shortest path from 
				// i to j, then update the value of dist[i][j] 
				if(dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 

	// Print the shortest distance matrix 
	printSolution(tam,dist); 
} 

void dijkstraA (int tam,int graph[][tam]){ 
	/* dist[][] will be the output matrix that will finally have the shortest 
	distances between every pair of vertices */
	int dist[tam][tam], i, j, k; 

	/* Initialize the solution matrix same as input graph matrix. Or 
	we can say the initial values of shortest distances are based 
	on shortest paths considering no intermediate vertex. */
	for (i = 0; i < tam; i++) 
		for (j = 0; j < tam; j++)
			if(i==j)
				dist[i][j] = 0;
			else if(graph[i][j]== -1 && i!=j)
				dist[i][j]=INF;
			else
				dist[i][j] = graph[i][j]; 

	for(k = 0; k < tam; k++)
		for(i = 0; i < tam; i++){ 
			// Pick all vertices as destination for the 
			// above picked source 
			for(j = 0; j < tam; j++){
				// If vertex k is on the shortest path from 
				// i to j, then update the value of dist[i][j] 
				if(dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		}
	for(i=0;i<tam;i++)
		for(j=0;j<tam;j++)
			if(dist[i][j] != 0)
				printf("From nodde %d to node %d: %d\n",i,j,dist[i][j] );
}

/* A utility function to print solution */
void printSolution(int tam,int dist[][tam]){
	for (int i = 0; i < tam; i++){ 
		for (int j = 0; j < tam; j++){
			if (dist[i][j] == INF)
				printf("%7s", "INF"); 
			else
				printf ("%7d", dist[i][j]); 
		} 
		printf("\n"); 
	}
}

int main(int argc, char const *argv[]){
	int tam=0;
	int lnum=0;
	char tmpNum[20];
	fgets(tmpNum,19,stdin);
	tam = atoi(tmpNum);
	int matrix[tam][tam],dfs[tam];
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			fgets(tmpNum,19,stdin);
			matrix[i][j] = atoi(tmpNum);
			if(lnum<knowlength(matrix[i][j])){
				lnum = knowlength(matrix[i][j]);
			}
		}
	}
	printf("Adjency Matrix:\n");
	adjacencyMatrix(*matrix,tam,lnum+1);
	printf("\nEdge List:\n");
	printEdgelist(*matrix,tam,lnum+1);
	printf("\nAdjacency List:\n");
	printAdjacencylist(*matrix,tam,lnum+1);
	printf("\nDijkstra:\n" );
	dijkstraA(tam,matrix);
	printf("\nFloyd matrix: \n");
	floydWarshall(tam,matrix);
	printf("\nBFS: \n");
	printBFS(tam,matrix);
	printf("\nDFS: \n");
	pruebaDFS(tam,matrix,dfs);
	return 0;
}