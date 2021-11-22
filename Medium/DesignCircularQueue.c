


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

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
