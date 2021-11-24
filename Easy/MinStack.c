


typedef struct {
    int *s;
    int *min;
    int top;
} MinStack;


MinStack* minStackCreate() {
    MinStack *obj = (MinStack*)malloc(sizeof(MinStack));
    obj->s = (int*)malloc(sizeof(int)*30000);
    obj->min = (int*)malloc(sizeof(int)*30000);
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->s[obj->top] = val;
    
    if(obj->top == 0)
        obj->min[obj->top] = val;
    else
        obj->min[obj->top] = ((obj->min[obj->top-1])>val) ? val : (obj->min[obj->top-1]);
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->s[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->top] ;
}

void minStackFree(MinStack* obj) {
    free(obj->s);
    free(obj->min);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
