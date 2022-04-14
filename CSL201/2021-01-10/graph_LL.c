#include<stdlib.h>
#include<stdio.h>

typedef struct graph_vertex{
    char data;
    int visited;
} vertex;

typedef struct graph_edge{
    int start;
    int end;
} edge;


/*
void addEdge(edge* list_of_edges,int* num_of_edges,int start, int end){

}
*/

void addVertex(vertex* list_of_vertex,int* num_of_vertex, int data){
    list_of_vertex[(*num_of_vertex)].data = (char) data;
    list_of_vertex[(*num_of_vertex)].visited = 0;
    (*num_of_vertex) = (*num_of_vertex)+1;
}

void main(){
    vertex* lv = (vertex*)malloc(sizeof(vertex)*20);
    edge* le = (edge*)malloc(sizeof(edge)*20);
    int RUN = 1,nv = 0,ne=0,i=0;
    char c;
    printf("BFS and DFS implementation\n");
    printf("Enter the number of vertices: ");
    scanf("%d%*c",&nv);
    //fflush(stdin);
    printf("\nEnter the vertices of the Graph: ");
    while(i<nv){
        c = getchar();//scanf("%c\n",&c);
        getchar();
        //printf("\nIn the while loop value of c = %c\n", c);
        addVertex(lv,&i,c);
    }
    for(int i=0;i<nv;i++){
        printf("%c\n",lv[i].data);
    }
    i=0;

    printf("Enter the number of edges in the graph: ");
    scanf("%d%*c",&ne);
    while()
}
