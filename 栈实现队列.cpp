typedef struct {
    stack spush;
    stack spop;
} MyQueue;
MyQueue* myQueueCreate() {
    MyQueue* mq = ( MyQueue*)malloc(sizeof(MyQueue));
    stackinit(&mq->spush,10);
    stackinit(&mq->spop,10);
    return mq;
}
void myQueuePush(MyQueue* obj, int x) {
    stackpush(&obj->spush,x);
}
int myQueuePop(MyQueue* obj) {
    int ret;
    if(stackempty(&obj->spop))
    {
        while(stackempty(&obj->spush)!=1)
        {
            int top = stacktop(&obj->spush);
            stackpop(&obj->spush);
            stackpush(&obj->spop,top);
        }
    }
    ret = stacktop(&obj->spop);
    stackpop(&obj->spop);
    return ret;
}
int myQueuePeek(MyQueue* obj) {
    int ret;
    if(stackempty(&obj->spop))
    {
        while(stackempty(&obj->spush)!=1)
        {
            int top = stacktop(&obj->spush);
            stackpop(&obj->spush);
            stackpush(&obj->spop,top);
        }
    }
    return stacktop(&obj->spop);
}
bool myQueueEmpty(MyQueue* obj) {
    return stackempty(&obj->spush)&&stackempty(&obj->spop);
}
void myQueueFree(MyQueue* obj) {
    stackdestory(&obj->spush);
    stackdestory(&obj->spop);
    free(obj);
}
