/* queue implement */
typedef struct {
    char **q;
    int head;
    int tail;
    int size;
    int len;
} Queue;


Queue* queueCreate(int k) {
    Queue *obj = (Queue *)malloc(sizeof(Queue));
    obj->q = (char **)malloc(sizeof(char *)*k);
    obj->size = k;
    obj->head = 0;
    obj->tail = -1;
    obj->len = 0;

    return obj;
}

bool enQueue(Queue* obj, char* value) {
    if(obj->len == obj->size)
        return false;
    
    obj->tail = (obj->tail+1)%obj->size;
    obj->q[obj->tail] = value;
    obj->len++;
    return true;
}

bool deQueue(Queue* obj) {
    if(obj->len == 0)
        return false;
    
    obj->head = (obj->head+1)%obj->size;
    obj->len--;
    return true;
}

char* queueFront(Queue* obj) {
    if(obj->len == 0)
        return "null";
    
    return obj->q[obj->head];
}

char* queueRear(Queue* obj) {
    if(obj->len == 0)
        return "null";
    
    return obj->q[obj->tail];
}

void queueFree(Queue* obj) {
    free(obj->q);
}

/* traverse */
bool ifdeadends(char ** deadends, int deadendsSize, char* cur){
    for(int i=0; i<deadendsSize; i++){
        if(!strcmp(cur, deadends[i]))
            return true;
    }
    return false;
}

int openLock(char ** deadends, int deadendsSize, char * target){
    if(!strcmp(target, "0000"))
        return 0;
    if(ifdeadends(deadends, deadendsSize, "0000"))
        return -1;
    
    Queue* queue = queueCreate(10000);
    int visited[10000] = {0};
    
    int t = enQueue(queue, "0000");
    visited[0] = 1;
    int step = -1;
    char *cur;
    while(queue->len > 0){
        step++;
        int size = queue->len;
        for(int n=0; n<size; n++){
            cur = queueFront(queue);
            if(!strcmp(target, cur))
                return step;

            for(int i=0; i<4; i++){
                char *ner_t = (char*)malloc(sizeof(char)*5); 
                char *ner_b = (char*)malloc(sizeof(char)*5); 
                
                char t = cur[i]+1;
                char b = cur[i]-1;
                if(cur[i] == '0')
                    b += 10;
                if(cur[i] == '9')
                    t -= 10;

                for(int j=0; j<4; j++){
                    if(i==j){
                        ner_t[j] = t;
                        ner_b[j] = b;
                    }
                    else{
                        ner_t[j] = cur[j];
                        ner_b[j] = cur[j];
                    }
                }
                ner_t[4] = '\0';
                ner_b[4] = '\0';
                
                if(!visited[atoi(ner_t)] &&!ifdeadends(deadends, deadendsSize, ner_t)){
                    t = enQueue(queue, ner_t);
                    visited[atoi(ner_t)] = 1;
                }
                if(!visited[atoi(ner_b)] && !ifdeadends(deadends, deadendsSize, ner_b)){
                    t = enQueue(queue, ner_b);
                    visited[atoi(ner_b)] = 1;
                }
            }
            t = deQueue(queue);
        }
    }
    return -1;
}
