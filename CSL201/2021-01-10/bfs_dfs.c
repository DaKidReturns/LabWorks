/* Breadth first and depth first search 
 * Done By: Rohit Karunakaran
 */
#include<stdlib.h>
#include<stdio.h>

int dequeue(int *q,int *f, int *b){
    int elem = q[*f];
    if((*f)==(*b)){
        (*f)=(*b)=-1;
    }
    else{
        (*f)++;
    }
    return elem;
}

void enqueue(int *q, int *f, int *b, int elem)
{
    (*b) = (*b)+1;
    q[(*b)] = elem;
    if((*f)==-1){
        (*f)++;
    }
}

void bfs(int* vert, int** a_m, int nv,int ne){
    if(nv!=0){
        int queue[2*nv];
        int f=0, b=0; //We put the fist element in the queue
        int visited[nv];
        int vc=0;

        int i=0; //nodes accessed.
        visited[0]=i; //visited the 0th node since it is added to the queue
        queue[f] = i;

        while(f!=-1){
            int c = dequeue(queue,&f,&b);

            for(int i = 0; i<nv;i++){  //itereate through all the edges

                if(a_m[c][i]==1){     //If an edge is connected to c

                    int flag=1;
                    for(int j = 0;j<=vc;j++) //check if the edge is visited
                    {
                        flag ==1;
                        if(visited[j]==i){
                            flag = 0;
                            break;
                        }
                    }

                    if(flag){ //If the edge is not visited then visit it....
                        enqueue(queue,&f,&b,i);
                        visited[++vc] = i;
                    }
                }
            }
        }

        for(int i = 0;i<=vc;i++){
            printf("%d ",vert[visited[i]]);
        }
    }
}

void dfs(int* vert, int** a_m, int nv,int ne){
    if(nv!=0){
        int stack[2*nv];
        int top=0;
        int visited[nv];
        int vc=-1;

        int i=0; //nodes accessed.
        stack[top] = i;

        while(top!=-1){
            int c = stack[top--];
            int flag = 1;
            for(int j = 0;j<=vc;j++){ //check if the edge is visited{
                if(visited[j]==c){
                    flag = 0;
                    break;
                }
            }

            if(flag){
                visited[++vc] = c;
                for(int i = 0;i<nv;i++){
                    if(a_m[c][i]==1){
                        stack[++top] = i;
                    }
                }
            }
        }

        for(int i = 0;i<=vc;i++){
            printf("%d ",vert[visited[i]]);
        }
    }
}

void main(){
    int nv,ne;

    printf("BFS and DFS implementation\n");
    printf("Enter the number of vertices: ");
    scanf("%d%*c",&nv);

    int** adj_matrix = (int**)calloc(nv,sizeof(int*));
    for(int i = 0;i<nv;i++)
        adj_matrix[i] = (int*)calloc(nv,sizeof(int));

    int *vertices = (int*)malloc(nv*sizeof(int ));

    printf("\nEnter the vertices of the Graph: ");
    for(int i=0;i<nv;i++){
        scanf("%d",&vertices[i]);
    }

    printf("Enter the number of edges: ");
    scanf("%d",&ne);
    
    printf("Enter the vetices connected by the edges in the form-> start end\n");
    for(int i=0;i<ne;){
        int s,e;
        if(scanf("%d %d",&s,&e)==2){
            adj_matrix[s][e]=1;
            adj_matrix[e][s]=1;
            i++;
        }
        else{
            printf("Enter the vertices in the correct format\n");
            
        }
    }
    printf("The Breadth first traversl: ");
    bfs(vertices, adj_matrix,nv,ne);
    printf("\n");


    printf("The Depth first traversal: ");
    dfs(vertices,adj_matrix,nv,ne);
    printf("\n");

}
