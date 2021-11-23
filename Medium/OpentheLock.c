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

void enQueue(Queue* obj, char* value) {
    obj->tail = (obj->tail+1)%obj->size;
    obj->q[obj->tail] = value;
    obj->len++;
}

char* deQueue(Queue* obj) {
    char *value = obj->q[obj->head];
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
    enQueue(queue, "0000");
    visited[0] = 1;
    int step = -1;
    char *cur;
    while(queue->len > 0){
        step++;
        int size = queue->len;
        for(int n=0; n<size; n++){
            cur = deQueue(queue);
            if(!strcmp(target, cur))
                return step;

            for(int i=0; i<4; i++){
                char *ner_inc = (char*)malloc(sizeof(char)*5);
                memcpy(ner_inc, cur, sizeof(char)*5);
                if(cur[i] == '9')
                    ner_inc[i] = '0';
                else
                    ner_inc[i] += 1;
                if(!visited[atoi(ner_inc)]){
                    enQueue(queue, ner_inc);
                    visited[atoi(ner_inc)] = 1;
                }
                
                char *ner_dec = (char*)malloc(sizeof(char)*5);
                memcpy(ner_dec, cur, sizeof(char)*5);
                if(cur[i] == '0')
                    ner_dec[i] = '9';
                else
                    ner_dec[i] -= 1;
                if(!visited[atoi(ner_dec)]){
                    enQueue(queue, ner_dec);
                    visited[atoi(ner_dec)] = 1;
                }
            }
        }
    }
    return -1;
}
