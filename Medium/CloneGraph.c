/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node *DFS(struct Node *s, struct Node **visited){
    struct Node *clone = (struct Node *)malloc(sizeof(struct Node));
    clone->neighbors = (struct Node **)malloc(sizeof(struct Node*)*s->numNeighbors);
    clone->val = s->val;
    clone->numNeighbors = s->numNeighbors;

    visited[s->val-1] = clone;

    for(int i=0; i<s->numNeighbors; i++){
        if(visited[s->neighbors[i]->val-1] == NULL){
            clone->neighbors[i] = DFS(s->neighbors[i], visited);
        }
        else{
            clone->neighbors[i] = visited[s->neighbors[i]->val-1];
        }
    }
    return clone;
}


struct Node *cloneGraph(struct Node *s) {
    if(s == NULL)
        return NULL;
    
    struct Node **visited = calloc(100, sizeof(struct Node *));
    struct Node *clone = DFS(s, visited);
    
    return clone;
}
