/* queue implement */
typedef struct {
    int *q;
    int head;
    int tail;
    int size;
    int len;
} Queue;


Queue* queueCreate(int k) {
    Queue *obj = (Queue *)malloc(sizeof(Queue));
    obj->q = (int *)malloc(sizeof(int)*k);
    obj->size = k;
    obj->head = 0;
    obj->tail = -1;
    obj->len = 0;

    return obj;
}

void enQueue(Queue* obj, int value) {
    obj->tail = (obj->tail+1)%obj->size;
    obj->q[obj->tail] = value;
    obj->len++;
}

int deQueue(Queue* obj) {
    int value = obj->q[obj->head];
    obj->head = (obj->head+1)%obj->size;
    obj->len--;
    return value;
}

/* traverse */
int openLock(char ** deadends, int deadendsSize, char * target){
    if(!strcmp(target, "0000"))
        return 0;
    
    int visited[10000] = {0};
    for(int i=0; i<deadendsSize; i++)
        visited[atoi(deadends[i])] = 1;
    if(visited[0])
        return -1;
    
    Queue* queue = queueCreate(10000);
    enQueue(queue, 0);
    visited[0] = 1;
    int step = -1, tar = atoi(target), cur;
    while(queue->len > 0){
        step++;
        int size = queue->len;
        for(int n=0; n<size; n++){
            cur = deQueue(queue);
            if(cur == tar)
                return step;

            int digit = cur;
            for(int i=3; i>=0; i--){
                int base = (int)pow(10,i), ner;
                
                ner = cur;
                if(digit/base == 9)
                    ner = ner - 9*base;
                else
                    ner += base;
                if(!visited[ner]){
                    enQueue(queue, ner);
                    visited[ner] = 1;
                }

                ner = cur;
                if(digit/base == 0)
                    ner = ner + 9*base;
                else
                    ner -= base;
                if(!visited[ner]){
                    enQueue(queue, ner);
                    visited[ner] = 1;
                }
                
                if(digit != 0)
                    digit %= base;
            }
        }
    }
    return -1;
}
