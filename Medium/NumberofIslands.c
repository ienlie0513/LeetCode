//queue implementation
typedef struct {
    int *q;
    int head;
    int tail;
    int size;
    int len;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    obj->q = (int *)malloc(sizeof(int)*k);
    obj->size = k;
    obj->head = 0;
    obj->tail = -1;
    obj->len = 0;

    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->len == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->len == obj->size;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj)){
        return false;
    }
    
    obj->tail = (obj->tail+1)%obj->size;
    obj->q[obj->tail] = value;
    obj->len++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return false;
    }
    
    obj->head = (obj->head+1)%obj->size;
    obj->len--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    
    return obj->q[obj->head];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj)){
        return -1;
    }
    
    return obj->q[obj->tail];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->q);
}


// BFS
void BFS(char** grid, int gridSize, int* gridColSize, int *visited, int i, int j){
    MyCircularQueue *queue = myCircularQueueCreate(gridSize*(*gridColSize));
    
    int t = myCircularQueueEnQueue(queue, i*(*gridColSize)+j);
    visited[i*(*gridColSize)+j] = 1;
    
    int cur;
    while(queue->len>0){
        cur = myCircularQueueFront(queue);
        
        i = cur/(*gridColSize);
        j = cur%(*gridColSize);
        if(i>0 && grid[i-1][j]-'0' && !visited[(i-1)*(*gridColSize)+j]){
            t = myCircularQueueEnQueue(queue, (i-1)*(*gridColSize)+j);
            visited[(i-1)*(*gridColSize)+j] = 1;
        }
        if(j>0 && grid[i][j-1]-'0' && !visited[i*(*gridColSize)+j-1]){
            t = myCircularQueueEnQueue(queue, i*(*gridColSize)+j-1);
            visited[i*(*gridColSize)+j-1] = 1;
        }
        if(i<gridSize-1 && grid[i+1][j]-'0' && !visited[(i+1)*(*gridColSize)+j]){
            t = myCircularQueueEnQueue(queue, (i+1)*(*gridColSize)+j);
            visited[(i+1)*(*gridColSize)+j] = 1;
        }
        if(j<(*gridColSize)-1 && grid[i][j+1]-'0' && !visited[i*(*gridColSize)+j+1]){
            t = myCircularQueueEnQueue(queue, i*(*gridColSize)+j+1);
            visited[i*(*gridColSize)+j+1] = 1;
        }
        
        t = myCircularQueueDeQueue(queue);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int cnt = 0;
    int *visited = (int*)malloc(sizeof(int)*gridSize*(*gridColSize));
    for(int i=0; i<gridSize*(*gridColSize); i++)
        visited[i] = 0;
    
    for(int i=0; i<gridSize; i++){
        for(int j=0; j<*gridColSize; j++){
            if(grid[i][j]-'0' && !visited[i*(*gridColSize)+j]){
                BFS(grid, gridSize, gridColSize, visited, i, j);
                cnt += 1;
            }
        }
    }
        
    return cnt;
}
